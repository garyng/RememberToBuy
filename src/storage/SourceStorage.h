#pragma once
#include "JsonStorage.h"
#include "models/Source.h"

class SourceStorage : public JsonStorage<Source>
{
public:
	SourceStorage(const std::shared_ptr<ILogger>& logger);

protected:
	std::string Filename() const override;
	std::vector<Source> DefaultData() const override;
};
