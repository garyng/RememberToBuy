#pragma once
#include "RemoveCartItem.h"
#include "storage/CartItemStorage.h"

class RemoveCartItemCommandHandler : public ICommandHandler<RemoveCartItem>
{
private:
	std::shared_ptr<CartItemStorage> _storage;
public:
	RemoveCartItemCommandHandler(const std::shared_ptr<CartItemStorage>& cartItemStorage);

	void Handle(RemoveCartItem& parameter) override;
};
