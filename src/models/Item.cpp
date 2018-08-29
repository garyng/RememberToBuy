#include "stdafx.h"
#include <string>
#include "Item.h"

Item::Item() = default;

Item::Item(const int id, const std::string& name, const int categoryId) : _id(id),
                                                                          _name(name),
                                                                          _categoryId(categoryId)
{
}

int Item::Id() const
{
	return _id;
}

void Item::Id(int value)
{
	_id = value;
}

std::string Item::Name() const
{
	return _name;
}

void Item::Name(std::string value)
{
	_name = value;
}

int Item::CategoryId() const
{
	return _categoryId;
}

void Item::CategoryId(int value)
{
	_categoryId = value;
}

void to_json(nlohmann::json& json, const Item& item)
{
	json = nlohmann::json{
		{"Id", item.Id()},
		{"Name", item.Name()},
		{"CategoryId", item.CategoryId()}
	};
}

void from_json(const nlohmann::json& json, Item& item)
{
	item.Id(json.at("Id").get<int>());
	item.Name(json.at("Name").get<std::string>());
	item.CategoryId(json.at("CategoryId").get<int>());
}
