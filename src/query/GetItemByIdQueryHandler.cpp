#include "stdafx.h"
#include "GetItemByIdQueryHandler.h"

GetItemByIdQueryHandler::
GetItemByIdQueryHandler(const std::shared_ptr<ItemStorage>& storage): GetByIdQueryHandlerBase<
	GetItemById, Item, ItemStorage>(storage)
{
}
