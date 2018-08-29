#pragma once
#include "JsonStorage.h"
#include "models/StockItem.h"

class StockItemStorage : public JsonStorage<StockItem>
{
public:
	StockItemStorage(const std::shared_ptr<ILogger>& logger);

protected:
	std::string Filename() const override;
	std::vector<StockItem> DefaultData() const override;
};
