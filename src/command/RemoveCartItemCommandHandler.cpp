#include "stdafx.h"
#include "RemoveCartItemCommandHandler.h"

RemoveCartItemCommandHandler::
RemoveCartItemCommandHandler(const std::shared_ptr<CartItemStorage>& cartItemStorage): _storage(cartItemStorage)
{
}

void RemoveCartItemCommandHandler::Handle(RemoveCartItem& parameter)
{
	_storage->Data().erase(
		std::remove_if(_storage->Data().begin(), _storage->Data().end(),
		               [&](const CartItem& item)
		               {
			               return item.Id() == parameter.id;
		               }));

	_storage->Save();
}