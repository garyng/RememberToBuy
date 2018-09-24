#include "stdafx.h"
#include "GetBestSourceByItemIdQueryHandler.h"

GetBestSourceByItemIdQueryHandler::GetBestSourceByItemIdQueryHandler(
	const std::shared_ptr<ItemSourceStorage>& itemSourceStorage, const std::shared_ptr<ProxyFactory>& proxyFactory):
	_itemSourceStorage(itemSourceStorage),
	_proxyFactory(proxyFactory)
{
}

ItemSource GetBestSourceByItemIdQueryHandler::Handle(GetBestSourceByItemId parameter)
{
	ItemSource bestSource = _itemSourceStorage->Data()
		| order_by([](ItemSource itemSource)
		{
			return itemSource.Price();
		})
		| where([&](ItemSource itemSource)
		{
			return itemSource.ItemId() == parameter.itemId;
		})
		| first();
	_proxyFactory->Apply(bestSource);
	return bestSource;
}
