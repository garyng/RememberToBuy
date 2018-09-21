#pragma once
#include "proxy/ProxyFactory.h"
#include "GetAllCartItemsByPredicate.h"
#include "storage/CartItemStorage.h"

class GetAllCartItemsByPredicateQueryHandler : public IQueryHandler<GetAllCartItemsByPredicate, std::vector<CartItem>>
{
private:
	std::shared_ptr<CartItemStorage> _storage;
	std::shared_ptr<ProxyFactory> _proxy;
public:

	GetAllCartItemsByPredicateQueryHandler(const std::shared_ptr<CartItemStorage>& cartItemStorage,
	                                       const std::shared_ptr<ProxyFactory>& proxyFactory);

	std::vector<CartItem> Handle(GetAllCartItemsByPredicate parameter) override;
};
