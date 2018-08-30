#pragma once
#include "JsonStorage.h"
#include "models/PendingItem.h"

class PendingItemStorage : public JsonStorage<PendingItem>
{
public:
	PendingItemStorage(const std::shared_ptr<ILogger>& logger);

protected:
	std::string Filename() const override;
	std::vector<PendingItem> DefaultData() const override;
};
