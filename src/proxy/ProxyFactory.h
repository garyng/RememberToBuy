#pragma once
#include "ItemProxy.h"
#include "models/CartItem.h"
#include "SourceProxy.h"
#include "ItemSourceProxy.h"

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

	void Apply(CartItem& cartItem)
	{
		if (!cartItem.Item())
		{
			cartItem.Item(ItemProxyFactory(cartItem.ItemId()));
		}
		if (!cartItem.Source())
		{
			cartItem.Source(SourceProxyFactory(cartItem.SourceId()));
		}
		if (!cartItem.ItemSource())
		{
			cartItem.ItemSource(ItemSourceProxyFactory(cartItem.ItemId(), cartItem.SourceId()));
		}
	}

	void Apply(Item& item)
	{
		if (!item.Category())
		{
			item.Category(CategoryProxyFactory(item.CategoryId()));
		}
	}


	template <class T>
	void Apply(T& item)
	{
		// no proxy available for the item
	}

	ItemProxy ItemProxyFactory(int id)
	{
		return ItemProxy{_queryDispatcher, id};
	}

	CategoryProxy CategoryProxyFactory(int id)
	{
		return CategoryProxy{_queryDispatcher, id};
	}

	SourceProxy SourceProxyFactory(int id)
	{
		return SourceProxy{_queryDispatcher, id};
	}

	ItemSourceProxy ItemSourceProxyFactory(int itemId, int sourceId)
	{
		return ItemSourceProxy{_queryDispatcher, itemId, sourceId};
	}
};
