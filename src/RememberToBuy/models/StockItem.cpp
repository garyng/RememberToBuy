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
