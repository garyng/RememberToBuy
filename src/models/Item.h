#pragma once
#include <string>
#include <nlohmann/json.hpp>
#include "proxy/CategoryProxy.h"

class Item
{
private:
	int _id{};
	std::string _name;
	int _categoryId{};

	CategoryProxy _category{};

public:
	Item();
	Item(const int id, const std::string& name, const int categoryId);

	int Id() const;
	void Id(int value);

	std::string Name() const;
	void Name(std::string value);

	int CategoryId() const;
	void CategoryId(int value);

	CategoryProxy Category() const { return _category; }
	void Category(CategoryProxy value) { _category = value; }
};

void to_json(nlohmann::json& json, const Item& item);
void from_json(const nlohmann::json& json, Item& item);
