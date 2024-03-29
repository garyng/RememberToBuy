﻿#include "stdafx.h"
#include "HistoryItem.h"

HistoryItem::HistoryItem(const int id, const int itemId, const int quantity, const int sourceId, const double price,
                         const std::string& date): _id(id),
                                                   _itemId(itemId),
                                                   _quantity(quantity),
                                                   _sourceId(sourceId),
                                                   _price(price),
                                                   _date(date)
{
}

HistoryItem::HistoryItem() = default;

int HistoryItem::Id() const
{
	return _id;
}

void HistoryItem::Id(int value)
{
	_id = value;
}

int HistoryItem::ItemId() const
{
	return _itemId;
}

void HistoryItem::ItemId(int value)
{
	_itemId = value;
}

ItemProxy HistoryItem::Item() const
{
	return _item;
}

void HistoryItem::Item(ItemProxy value)
{
	_item = value;
}

SourceProxy HistoryItem::Source() const
{
	return _source;
}

void HistoryItem::Source(SourceProxy value)
{
	_source = value;
}

int HistoryItem::Quantity() const
{
	return _quantity;
}

void HistoryItem::Quantity(int value)
{
	_quantity = value;
}

int HistoryItem::SourceId() const
{
	return _sourceId;
}

void HistoryItem::SourceId(int value)
{
	_sourceId = value;
}

double HistoryItem::Price() const
{
	return _price;
}

void HistoryItem::Price(double value)
{
	_price = value;
}

std::string HistoryItem::Date() const
{
	return _date;
}

void HistoryItem::Date(std::string value)
{
	_date = value;
}

void to_json(nlohmann::json& json, const HistoryItem& historyItem)
{
	json = nlohmann::json{
		{"Id", historyItem.Id()},
		{"ItemId", historyItem.ItemId()},
		{"Quantity", historyItem.Quantity()},
		{"SourceId", historyItem.SourceId()},
		{"Price", historyItem.Price()},
		{"Date", historyItem.Date()}
	};
}

void from_json(const nlohmann::json& json, HistoryItem& historyItem)
{
	historyItem.Id(json.at("Id").get<int>());
	historyItem.ItemId(json.at("ItemId").get<int>());
	historyItem.Quantity(json.at("Quantity").get<int>());
	historyItem.SourceId(json.at("SourceId").get<int>());
	historyItem.Price(json.at("Price").get<double>());
	historyItem.Date(json.at("Date").get<std::string>());
}
