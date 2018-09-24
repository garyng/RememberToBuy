#include "stdafx.h"
#include "UpdateSourceByCartItemIdCommandHandler.h"

UpdateSourceByCartItemIdCommandHandler::UpdateSourceByCartItemIdCommandHandler(
	const std::shared_ptr<CartItemStorage>& cartItemStorage, const std::shared_ptr<ProxyFactory>& proxyFactory):
	_cartItemStorage(cartItemStorage),
	_proxyFactory(proxyFactory)
{
}

void UpdateSourceByCartItemIdCommandHandler::Handle(UpdateSourceByCartItemId& parameter)
{
	CartItem& cartItem = _cartItemStorage->Data()
		| first([&](CartItem item)
		{
			return item.Id() == parameter.cartItemId;
		});

	cartItem.SourceId(parameter.sourceId);
	_proxyFactory->Apply(cartItem);
	_cartItemStorage->Save();
}