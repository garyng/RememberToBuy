#include "stdafx.h"
#include "ItemSource.h"

ItemSource::ItemSource(const int id, const int itemId, const int sourceId, const double price): _id(id),
                                                                                                _itemId(itemId),
                                                                                                _sourceId(sourceId),
                                                                                                _price(price)
{
}

ItemSource::ItemSource() = default;

int ItemSource::Id() const
{
	return _id;
}

void ItemSource::Id(int value)
{
	_id = value;
}

int ItemSource::ItemId() const
{
	return _itemId;
}

void ItemSource::ItemId(int value)
{
	_itemId = value;
}

int ItemSource::SourceId() const
{
	return _sourceId;
}

void ItemSource::SourceId(int value)
{
	_sourceId = value;
}

double ItemSource::Price() const
{
	return _price;
}

void ItemSource::Price(double value)
{
	_price = value;
}
