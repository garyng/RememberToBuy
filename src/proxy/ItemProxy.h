#pragma once
#include "query/QueryDispatcher.h"
#include "models/Item.h"
#include "query/GetItemById.h"
#include "ProxyBase.h"

class ItemProxy : public ProxyBase<Item>
{
private:
	int _itemId;

public:

	ItemProxy(const std::shared_ptr<QueryDispatcher>& queryDispatcher, const int itemId)
		: ProxyBase<Item>(queryDispatcher),
		  _itemId(itemId)
	{
	}

	Item Value() const override
	{
		return _queryDispatcher->Dispatch<Item>(GetItemById{_itemId});
	}
};