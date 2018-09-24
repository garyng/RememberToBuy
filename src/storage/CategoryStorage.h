#pragma once
#include "JsonStorage.h"
#include "models/Category.h"

class CategoryStorage : public JsonStorage<Category>
{
public:
	CategoryStorage(const std::shared_ptr<ILogger>& logger);

protected:
	std::string Filename() const override;
	std::vector<Category> DefaultData() const override;
};
