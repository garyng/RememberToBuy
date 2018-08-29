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
