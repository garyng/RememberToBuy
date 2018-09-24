#pragma once
#include "ItemProxy.h"
#include "models/CartItem.h"
#include "models/HistoryItem.h"
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

	template <class T>
	void Apply(std::vector<T>& items)
	{
		for (auto&& item : items)
		{
			Apply(item);
		}
	}

	void Apply(CartItem& cartItem)
	{
		cartItem.Item(ItemProxyFactory(cartItem.ItemId()));
		cartItem.Source(SourceProxyFactory(cartItem.SourceId()));
		cartItem.ItemSource(ItemSourceProxyFactory(cartItem.ItemId(), cartItem.SourceId()));
	}

	void Apply(Item& item)
	{
		item.Category(CategoryProxyFactory(item.CategoryId()));
	}

	void Apply(HistoryItem& historyItem)
	{
		historyItem.Item(ItemProxyFactory(historyItem.ItemId()));
		historyItem.Source(SourceProxyFactory(historyItem.SourceId()));
	}

	void Apply(ItemSource& itemSource)
	{
		itemSource.Item(ItemProxyFactory(itemSource.ItemId()));
		itemSource.Source(SourceProxyFactory(itemSource.SourceId()));
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
