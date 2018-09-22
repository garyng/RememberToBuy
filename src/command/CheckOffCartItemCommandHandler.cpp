#include "stdafx.h"
#include "CheckOffCartItemCommandHandler.h"
#include "models/HistoryItem.h"
#include "CheckOffCartItem.h"

void CheckOffCartItemCommandHandler::Handle(CheckOffCartItem& parameter)
{
	std::time_t t = std::time(nullptr);
	std::tm tm = *std::localtime(&t);

	std::ostringstream ss;
	ss << std::put_time(&tm, "%d-%m-%Y");
	std::string today = ss.str();

	int id = _historyItemStorage->Data()
		| select([](HistoryItem item) { return item.Id(); })
		| order_by_descending([](int id) { return id; })
		| first();
	id++;

	CartItem cartItem = _cartItemStorage->Data()
		| first([&](CartItem item)
		{
			return item.Id() == parameter.id;
		});

	_proxyFactory->Apply(cartItem);

	_historyItemStorage->Data().emplace_back(
		id, cartItem.ItemId(), cartItem.Quantity(),
		cartItem.SourceId(), cartItem.ItemSource().Value().Price(), today
	);

	_cartItemStorage->Data().erase(
		std::remove_if(_cartItemStorage->Data().begin(), _cartItemStorage->Data().end(),
		               [&](const CartItem& item)
		               {
			               return item.Id() == parameter.id;
		               }));

	_historyItemStorage->Save();
	_cartItemStorage->Save();
}
