#pragma once
#include <string>
#include <nlohmann/json.hpp>

class Category
{
private:
	int _id{};
	std::string _name;
	std::string _description;

public:

	Category(const int id, const std::string& name, const std::string& description);
	Category();

	int Id() const;
	void Id(int value);

	std::string Name() const;
	void Name(std::string value);

	std::string Description() const;
	void Description(std::string value);
};

void to_json(nlohmann::json& json, const Category& category);
void from_json(const nlohmann::json& json, Category& category);
