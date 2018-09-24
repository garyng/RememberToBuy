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

ItemProxy ItemSource::Item() const
{
	return _item;
}

void ItemSource::Item(ItemProxy value)
{
	_item = value;
}

SourceProxy ItemSource::Source() const
{
	return _source;
}

void ItemSource::Source(SourceProxy value)
{
	_source = value;
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

void to_json(nlohmann::json& json, const ItemSource& itemSource)
{
	json = nlohmann::json
	{
		{"Id", itemSource.Id()},
		{"ItemId", itemSource.ItemId()},
		{"SourceId", itemSource.SourceId()},
		{"Price", itemSource.Price()}
	};
}

void from_json(const nlohmann::json& json, ItemSource& itemSource)
{
	itemSource.Id(json.at("Id").get<int>());
	itemSource.ItemId(json.at("ItemId").get<int>());
	itemSource.SourceId(json.at("SourceId").get<int>());
	itemSource.Price(json.at("Price").get<double>());
}
