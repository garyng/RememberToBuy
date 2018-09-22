#include "stdafx.h"
#include "UpdateCartItemQuantityCommandHandler.h"

UpdateCartItemQuantityCommandHandler::UpdateCartItemQuantityCommandHandler(
	const std::shared_ptr<CartItemStorage>& cartItemStorage): _storage(cartItemStorage)
{
}

void UpdateCartItemQuantityCommandHandler::Handle(UpdateCartItemQuantity& parameter)
{
	using namespace coveo::linq;

	CartItem& result = _storage->Data()
		| first([&](CartItem cartItem)
		{
			return cartItem.Id() == parameter.Id;
		});

	result.Quantity(parameter.Quantity);
	_storage->Save();
}
