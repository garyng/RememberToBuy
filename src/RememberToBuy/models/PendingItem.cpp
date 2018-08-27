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

int PendingItem::Quantity() const
{
	return _quantity;
}

void PendingItem::Quantity(int value)
{
	_quantity = value;
}
