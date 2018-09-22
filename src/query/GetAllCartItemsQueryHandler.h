#pragma once
#include "models/CartItem.h"
#include "GetAllCartItems.h"
#include "storage/CartItemStorage.h"
#include "proxy/ProxyFactory.h"

class GetAllCartItemsQueryHandler : public IQueryHandler<GetAllCartItems, std::vector<CartItem>>
{
private:
	std::shared_ptr<CartItemStorage> _cartItemStorage;
	std::shared_ptr<ProxyFactory> _proxyFactory;
public:
	GetAllCartItemsQueryHandler(const std::shared_ptr<CartItemStorage>& cartItemStorage,
	                            const std::shared_ptr<ProxyFactory>& proxyFactory);
	std::vector<CartItem> Handle(GetAllCartItems parameter) override;
};