#pragma once
#include "ItemProxy.h"
#include "models/CartItem.h"

class ProxyFactory
{
private:
	std::shared_ptr<QueryDispatcher> _queryDispatcher;

public:
	ProxyFactory(const std::shared_ptr<QueryDispatcher>& queryDispatcher)
		: _queryDispatcher(queryDispatcher)
	{
	}

	void Apply(std::vector<CartItem>& cartItems)
	{
		for (CartItem& cartItem : cartItems)
		{
			Apply(cartItem);
		}
	}

	void Apply(CartItem& cartItem)
	{
		cartItem.Item(ItemProxyFactory(cartItem.Id()));
	}

	std::shared_ptr<ItemProxy> ItemProxyFactory(int itemId)
	{
		return std::make_shared<ItemProxy>(_queryDispatcher, itemId);
	}
};
