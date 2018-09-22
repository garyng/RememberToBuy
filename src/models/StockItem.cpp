#include "stdafx.h"
#include "StockItem.h"

StockItem::StockItem(const int id, const int quantity, const int itemId): _id(id),
                                                                          _quantity(quantity),
                                                                          _itemId(itemId)
{
}

StockItem::StockItem() = default;

int StockItem::Id() const
{
	return _id;
}

void StockItem::Id(int value)
{
	_id = value;
}

int StockItem::Quantity() const
{
	return _quantity;
}

void StockItem::Quantity(int value)
{
	_quantity = value;
}

int StockItem::ItemId() const
{
	return _itemId;
}

void StockItem::ItemId(int value)
{
	_itemId = value;
}

ItemProxy StockItem::Item() const
{
	return _item;
}

void StockItem::Item(ItemProxy value)
{
	_item = value;
}

void to_json(nlohmann::json& json, const StockItem& stockItem)
{
	json = nlohmann::json{
		{"Id", stockItem.Id()},
		{"ItemId", stockItem.ItemId()},
		{"Quantity", stockItem.Quantity()}
	};
}

void from_json(const nlohmann::json& json, StockItem& stockItem)
{
	stockItem.Id(json.at("Id").get<int>());
	stockItem.ItemId(json.at("ItemId").get<int>());
	stockItem.Quantity(json.at("Quantity").get<int>());
}
