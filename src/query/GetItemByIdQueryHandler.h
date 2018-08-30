#pragma once
#include "storage/ItemStorage.h"
#include "GetItemById.h"

class GetItemByIdQueryHandler : public IQueryHandler<GetItemById, Item>
{
private:
	std::shared_ptr<ItemStorage> _itemStorage;
public:
	GetItemByIdQueryHandler(const std::shared_ptr<ItemStorage>& itemStorage);

	Item Handle(GetItemById parameter) override;
};
