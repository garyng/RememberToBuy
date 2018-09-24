#pragma once
#include <command/ICommandHandler.h>
#include <coveo/linq.h>
#include "storage/CartItemStorage.h"
#include "UpdateCartItemQuantity.h"

class UpdateCartItemQuantityCommandHandler : public ICommandHandler<UpdateCartItemQuantity>
{
private:
	std::shared_ptr<CartItemStorage> _storage;
public:

	UpdateCartItemQuantityCommandHandler(const std::shared_ptr<CartItemStorage>& cartItemStorage);

	void Handle(UpdateCartItemQuantity& parameter) override;
};
