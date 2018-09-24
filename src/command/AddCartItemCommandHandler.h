#pragma once
#include "models/CartItem.h"
#include "AddCartItem.h"
#include "proxy/ProxyFactory.h"
#include "storage/CartItemStorage.h"

class AddCartItemCommandHandler : public ICommandHandler<AddCartItem>
{
private:
	std::shared_ptr<CartItemStorage> _cartItemStorage;
	std::shared_ptr<ProxyFactory> _proxyFactory;
public:

	AddCartItemCommandHandler(const std::shared_ptr<CartItemStorage>& cartItemStorage,
	                          const std::shared_ptr<ProxyFactory>& proxyFactory);

	void Handle(AddCartItem& parameter) override;
};
