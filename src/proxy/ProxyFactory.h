#pragma once
#include "ItemProxy.h"
#include "models/CartItem.h"

class ProxyFactory
{
private:
	std::shared_ptr<QueryDispatcher> _queryDispatcher;
	std::shared_ptr<ILogger> _logger;

public:
	ProxyFactory(const std::shared_ptr<QueryDispatcher>& queryDispatcher, const std::shared_ptr<ILogger>& logger)
		: _queryDispatcher(queryDispatcher),
		  _logger(logger)
	{
	}

	void Apply(std::vector<CartItem>& cartItems)
	{
		for (CartItem& cartItem : cartItems)
		{
			Apply(cartItem);
		}
	}

	// todo: apply vector<category>

	void Apply(CartItem& cartItem)
	{
		if (cartItem.Item()) return;
		cartItem.Item(ItemProxyFactory(cartItem.Id()));
	}

	void Apply(Item& item)
	{
		if (item.Category()) return;
		item.Category(CategoryProxyFactory(item.Id()));
	}

	template <class T>
	void Apply(T& item)
	{
		//_logger->Debug("No proxy available for " + std::string(typeid(item).name()));
	}

	ItemProxy ItemProxyFactory(int itemId)
	{
		return ItemProxy{_queryDispatcher, itemId};
	}

	CategoryProxy CategoryProxyFactory(int id)
	{
		return CategoryProxy{_queryDispatcher, id};
	}
};
