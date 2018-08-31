#include "stdafx.h"
#include "GetItemByIdQueryHandler.h"

GetItemByIdQueryHandler::GetItemByIdQueryHandler(const std::shared_ptr<ItemStorage>& storage,
                                                 const std::shared_ptr<ProxyFactory>& proxyFactory):
	GetByIdQueryHandlerBase<GetItemById, Item, ItemStorage>(storage, proxyFactory)
{
}
