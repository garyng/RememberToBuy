#include "stdafx.h"
#include "CartItem.h"

CartItem::CartItem(const int id, const int itemId, const int quantity, const int sourceId): _id(id),
                                                                                            _itemId(itemId),
                                                                                            _quantity(quantity),
                                                                                            _sourceId(sourceId)
{
}

CartItem::CartItem() = default;

int CartItem::Id() const
{
	return _id;
}

void CartItem::Id(int value)
{
	_id = value;
}

int CartItem::ItemId() const
{
	return _itemId;
}

void CartItem::ItemId(int value)
{
	_itemId = value;
}

int CartItem::Quantity() const
{
	return _quantity;
}

void CartItem::Quantity(int value)
{
	_quantity = value;
}

int CartItem::SourceId() const
{
	return _sourceId;
}

void CartItem::SourceId(int value)
{
	_sourceId = value;
}

void to_json(nlohmann::json& json, const CartItem& item)
{
	json = nlohmann::json{
		{"Id", item.Id()},
		{"ItemId", item.ItemId()},
		{"Quantity", item.Quantity()},
		{"SourceId", item.SourceId()}
	};
}

void from_json(const nlohmann::json& json, CartItem& item)
{
	item.Id(json.at("Id").get<int>());
	item.ItemId(json.at("ItemId").get<int>());
	item.Quantity(json.at("Quantity").get<int>());
	item.SourceId(json.at("SourceId").get<int>());
}
