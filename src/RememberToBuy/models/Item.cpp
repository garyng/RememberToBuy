#include "stdafx.h"
#include <string>
#include "Item.h"

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

Item::Item() = default;

Item::Item(const int id, const std::string& name, const int categoryId) : _id(id),
                                                                          _name(name),
                                                                          _categoryId(categoryId)
{
}
