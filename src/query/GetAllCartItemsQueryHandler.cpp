#include "stdafx.h"

#include <coveo/linq.h>
#include "GetAllCartItemsQueryHandler.h"

using namespace coveo::linq;

GetAllCartItemsQueryHandler::GetAllCartItemsQueryHandler(const std::shared_ptr<CartItemStorage>& cartItemStorage,
                                                         const std::shared_ptr<ProxyFactory>& proxyFactory):
	_cartItemStorage(cartItemStorage),
	_proxyFactory(proxyFactory)
{
}

std::vector<CartItem> GetAllCartItemsQueryHandler::Handle(GetAllCartItems parameter)
{
	std::vector<CartItem> cartItems = _cartItemStorage->Data();
	_proxyFactory->Apply(cartItems);
	return cartItems;
}
