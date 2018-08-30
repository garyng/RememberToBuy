#pragma once
#include "JsonStorage.h"
#include "models/ItemSource.h"

class ItemSourceStorage : public JsonStorage<ItemSource>
{
public:
	ItemSourceStorage(const std::shared_ptr<ILogger>& logger);

protected:
	std::string Filename() const override;
	std::vector<ItemSource> DefaultData() const override;
};
