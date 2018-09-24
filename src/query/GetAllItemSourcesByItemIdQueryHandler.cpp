#include "stdafx.h"
#include "GetAllItemSourcesByItemIdQueryHandler.h"

GetAllItemSourcesByItemIdQueryHandler::GetAllItemSourcesByItemIdQueryHandler(
	const std::shared_ptr<ItemSourceStorage>& itemSourceStorage, const std::shared_ptr<ProxyFactory>& proxyFactory):
	_itemSourceStorage(itemSourceStorage),
	_proxyFactory(proxyFactory)
{
}

std::vector<ItemSource> GetAllItemSourcesByItemIdQueryHandler::Handle(GetAllItemSourcesByItemId parameter)
{
	std::vector<ItemSource> result = _itemSourceStorage->Data()
		| where([&](ItemSource item)
		{
			return item.ItemId() == parameter.itemId;
		})
		| to_vector();
	_proxyFactory->Apply(result);
	return result;
}
