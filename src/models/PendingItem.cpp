#include "stdafx.h"
#include "PendingItem.h"

PendingItem::PendingItem(const int id, const int itemId, const int quantity): _id(id),
                                                                              _itemId(itemId),
                                                                              _quantity(quantity)
{
}

PendingItem::PendingItem() = default;

int PendingItem::Id() const
{
	return _id;
}

void PendingItem::Id(int value)
{
	_id = value;
}

int PendingItem::ItemId() const
{
	return _itemId;
}

void PendingItem::ItemId(int value)
{
	_itemId = value;
}

ItemProxy PendingItem::Item() const
{
	return _item;
}

void PendingItem::Item(ItemProxy value)
{
	_item = value;
}

int PendingItem::Quantity() const
{
	return _quantity;
}

void PendingItem::Quantity(int value)
{
	_quantity = value;
}

void to_json(nlohmann::json& json, const PendingItem& pendingItem)
{
	json = nlohmann::json{
		{"Id", pendingItem.Id()},
		{"ItemId", pendingItem.ItemId()},
		{"Quantity", pendingItem.Quantity()}
	};
}

void from_json(const nlohmann::json& json, PendingItem& pendingItem)
{
	pendingItem.Id(json.at("Id").get<int>());
	pendingItem.ItemId(json.at("ItemId").get<int>());
	pendingItem.Quantity(json.at("Quantity").get<int>());
}
