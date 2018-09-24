#pragma once
#include "models/ItemSource.h"
#include "query/GetItemSourceByItemIdAndSourceId.h"
#include "ProxyBase.h"

class ItemSourceProxy : public ProxyBase<ItemSource>
{
private:
	int _itemId{};
	int _sourceId{};
public:

	ItemSourceProxy(const std::shared_ptr<QueryDispatcher>& queryDispatcher, const int itemId, const int sourceId)
		: ProxyBase<ItemSource>(queryDispatcher),
		  _itemId(itemId),
		  _sourceId(sourceId)
	{
	}

	ItemSourceProxy()
	{
	}

	ItemSource Value() const override
	{
		return _queryDispatcher->Dispatch<ItemSource>(GetItemSourceByItemIdAndSourceId{_itemId, _sourceId});
	}
};
