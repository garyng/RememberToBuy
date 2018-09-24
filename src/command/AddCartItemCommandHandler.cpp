#include "stdafx.h"
#include "AddCartItemCommandHandler.h"

AddCartItemCommandHandler::AddCartItemCommandHandler(const std::shared_ptr<CartItemStorage>& cartItemStorage,
                                                     const std::shared_ptr<ProxyFactory>& proxyFactory):
	_cartItemStorage(cartItemStorage),
	_proxyFactory(proxyFactory)
{
}

void AddCartItemCommandHandler::Handle(AddCartItem& parameter)
{
	int id = _cartItemStorage->Data()
		| select([](CartItem cartItem) { return cartItem.Id(); })
		| order_by_descending([](int id) { return id; })
		| first();
	id++;
	parameter.id = id;

	_cartItemStorage->Data()
	                .emplace_back(id, parameter.itemId, 1, parameter.sourceId);

	_cartItemStorage->Save();
}
