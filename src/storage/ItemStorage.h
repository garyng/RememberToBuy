#pragma once
#include "JsonStorage.h"
#include "models/Item.h"

class ItemStorage : public JsonStorage<Item>
{
public:
	ItemStorage(const std::shared_ptr<ILogger>& logger);

protected:
	std::string Filename() const override;
	std::vector<Item> DefaultData() const override;
};
