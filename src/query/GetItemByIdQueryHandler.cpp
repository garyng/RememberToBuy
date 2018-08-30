#include "stdafx.h"
#include "GetItemByIdQueryHandler.h"

GetItemByIdQueryHandler::
GetItemByIdQueryHandler(const std::shared_ptr<ItemStorage>& itemStorage): _itemStorage(itemStorage)
{
}

Item GetItemByIdQueryHandler::Handle(GetItemById parameter)
{
	using namespace coveo::linq;

	return _itemStorage->Data()
		| first([&](Item item)
		{
			return item.Id() == parameter.Id;
		});
}
