#include "stdafx.h"
#include "Category.h"

Category::Category(const int id, const std::string& name, const std::string& description): _id(id),
                                                                                           _name(name),
                                                                                           _description(description)
{
}

Category::Category() = default;

int Category::Id() const
{
	return _id;
}

void Category::Id(int value)
{
	_id = value;
}

std::string Category::Name() const
{
	return _name;
}

void Category::Name(std::string value)
{
	_name = value;
}

std::string Category::Description() const
{
	return _description;
}

void Category::Description(std::string value)
{
	_description = value;
}

void to_json(nlohmann::json& json, const Category& category)
{
	json = nlohmann::json{
		{"Id", category.Id()},
		{"Name", category.Name()},
		{"Description", category.Description()}
	};
}

void from_json(const nlohmann::json& json, Category& category)
{
	category.Id(json.at("Id").get<int>());
	category.Name(json.at("Name").get<std::string>());
	category.Description(json.at("Description").get<std::string>());
}
