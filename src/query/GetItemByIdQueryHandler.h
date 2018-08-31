#pragma once
#include "storage/ItemStorage.h"
#include "GetItemById.h"
#include "GetByIdQueryHandlerBase.h"

class GetItemByIdQueryHandler : public GetByIdQueryHandlerBase<GetItemById, Item, ItemStorage>
{
public:
	GetItemByIdQueryHandler(const std::shared_ptr<ItemStorage>& storage,
	                        const std::shared_ptr<ProxyFactory>& proxyFactory);
};
