#pragma once
#include "JsonStorage.h"
#include "models/HistoryItem.h"

class HistoryItemStorage : public JsonStorage<HistoryItem>
{
public:
	HistoryItemStorage(const std::shared_ptr<ILogger>& logger);

protected:
	std::string Filename() const override;
	std::vector<HistoryItem> DefaultData() const override;
};
