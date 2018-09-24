#include "stdafx.h"
#include "GetAllItemsQueryHandler.h"

GetAllItemsQueryHandler::GetAllItemsQueryHandler(const std::shared_ptr<ItemStorage>& itemStorage,
                                                 const std::shared_ptr<ProxyFactory>& proxyFactory):
	_itemStorage(itemStorage),
	_proxyFactory(proxyFactory)
{
}

std::vector<Item> GetAllItemsQueryHandler::Handle(GetAllItems parameter)
{
	std::vector<Item> items = _itemStorage->Data();
	_proxyFactory->Apply(items);
	return items;
}
