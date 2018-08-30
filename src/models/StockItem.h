#pragma once
#include <nlohmann/json.hpp>

class StockItem
{
private:
	int _id{};
	int _quantity{};
	int _itemId{};

public:
	StockItem(const int id, const int quantity, const int itemId);
	StockItem();

	int Id() const;
	void Id(int value);

	int Quantity() const;
	void Quantity(int value);

	int ItemId() const;
	void ItemId(int value);
};

void to_json(nlohmann::json& json, const StockItem& stockItem);
void from_json(const nlohmann::json& json, StockItem& stockItem);
