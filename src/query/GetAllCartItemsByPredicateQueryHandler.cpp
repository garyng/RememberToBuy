#include "stdafx.h"
#include "GetAllCartItemsByPredicateQueryHandler.h"

GetAllCartItemsByPredicateQueryHandler::GetAllCartItemsByPredicateQueryHandler(
	const std::shared_ptr<CartItemStorage>& cartItemStorage, const std::shared_ptr<ProxyFactory>& proxyFactory):
	_storage(cartItemStorage),
	_proxy(proxyFactory)
{
}

std::vector<CartItem> GetAllCartItemsByPredicateQueryHandler::Handle(GetAllCartItemsByPredicate parameter)
{
	using namespace coveo::linq;

	std::vector<CartItem> cartItems = _storage->Data();
	_proxy->Apply(cartItems);
	return cartItems
		| where(parameter.predicate)
		| to_vector();
}
