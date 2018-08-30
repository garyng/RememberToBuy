#include "stdafx.h"
#include "ItemStorage.h"

ItemStorage::ItemStorage(const std::shared_ptr<ILogger>& logger): JsonStorage<Item>(logger)
{
}

std::string ItemStorage::Filename() const
{
	return NAMEOF(Item)".json";
}

std::vector<Item> ItemStorage::DefaultData() const
{
	return std::vector<Item>
	{
		{0, "Practical Cotton Bacon", 9},
		{1, "Sleek Steel Chair", 9},
		{2, "Handcrafted Granite Chair", 6},
		{3, "Incredible Soft Car", 7},
		{4, "Handmade Concrete Cheese", 8},
		{5, "Incredible Cotton Chicken", 7},
		{6, "Gorgeous Metal Pants", 5},
		{7, "Fantastic Steel Towels", 4},
		{8, "Rustic Metal Chair", 4},
		{9, "Awesome Plastic Shirt", 2},
		{10, "Gorgeous Concrete Keyboard", 5},
		{11, "Handmade Wooden Table", 3},
		{12, "Ergonomic Wooden Chair", 1},
		{13, "Intelligent Granite Ball", 0},
		{14, "Handmade Steel Chicken", 8},
		{15, "Handcrafted Granite Soap", 6},
		{16, "Tasty Granite Shoes", 6},
		{17, "Handmade Rubber Mouse", 4},
		{18, "Refined Granite Tuna", 1},
		{19, "Intelligent Wooden Chair", 1},
		{20, "Intelligent Frozen Table", 2},
		{21, "Tasty Cotton Ball", 6},
		{22, "Fantastic Frozen Fish", 5},
		{23, "Generic Rubber Hat", 7},
		{24, "Awesome Granite Soap", 1},
		{25, "Generic Soft Tuna", 4},
		{26, "Unbranded Rubber Gloves", 6},
		{27, "Unbranded Wooden Pizza", 6},
		{28, "Ergonomic Granite Soap", 6},
		{29, "Small Cotton Soap", 5},
		{30, "Gorgeous Fresh Ball", 7},
		{31, "Unbranded Metal Bacon", 2},
		{32, "Small Fresh Soap", 6},
		{33, "Sleek Soft Towels", 4},
		{34, "Fantastic Frozen Pants", 3},
		{35, "Ergonomic Rubber Chicken", 2},
		{36, "Ergonomic Wooden Table", 0},
		{37, "Tasty Fresh Fish", 1},
		{38, "Unbranded Steel Sausages", 7},
		{39, "Sleek Fresh Towels", 2},
		{40, "Licensed Steel Chicken", 0},
		{41, "Sleek Wooden Computer", 2},
		{42, "Unbranded Wooden Gloves", 0},
		{43, "Small Concrete Shoes", 6},
		{44, "Intelligent Frozen Fish", 7},
		{45, "Gorgeous Soft Pants", 1},
		{46, "Ergonomic Cotton Cheese", 4},
		{47, "Refined Fresh Chips", 5},
		{48, "Fantastic Wooden Soap", 1},
		{49, "Unbranded Rubber Cheese", 8}
	};
}
