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
