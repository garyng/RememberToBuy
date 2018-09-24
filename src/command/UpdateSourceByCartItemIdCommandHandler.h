#pragma once
#include "models/CartItem.h"
#include "UpdateSourceByCartItemId.h"
#include "proxy/ProxyFactory.h"
#include "storage/CartItemStorage.h"

class UpdateSourceByCartItemIdCommandHandler : public ICommandHandler<UpdateSourceByCartItemId>
{
private:
	std::shared_ptr<CartItemStorage> _cartItemStorage;
	std::shared_ptr<ProxyFactory> _proxyFactory;

public:
	UpdateSourceByCartItemIdCommandHandler(const std::shared_ptr<CartItemStorage>& cartItemStorage,
	                                       const std::shared_ptr<ProxyFactory>& proxyFactory);

	void Handle(UpdateSourceByCartItemId& parameter) override;
};
