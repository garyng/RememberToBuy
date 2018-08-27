#pragma once
#include <string>

class Item
{
private:
	int _id{};
	std::string _name;
	int _categoryId{};

public:
	Item();
	Item(const int id, const std::string& name, const int categoryId);

	int Id() const;
	void Id(int value);

	std::string Name() const;
	void Name(std::string value);

	int CategoryId() const;
	void CategoryId(int value);
};
