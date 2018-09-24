#include "stdafx.h"
#include "Sorter.h"
#include <coveo/linq.h>

void Sorter::Sort(std::vector<CartItem>& items, CartItemFields field, bool ascending)
{
	switch (field)
	{
		case CartItemFields::Quantity:
			OrderBy(items, ascending, [](CartItem item) { return item.Quantity(); });
			break;
		case CartItemFields::Name:
			OrderBy(items, ascending, [](CartItem item) { return item.Item().Value().Name(); });
			break;
		case CartItemFields::Source:
			OrderBy(items, ascending, [](CartItem item) { return item.Source().Value().Name(); });
			break;
	}
}

void Sorter::Sort(std::vector<HistoryItem>& items, HistoryItemFields field, bool ascending)
{
	switch (field)
	{
		case HistoryItemFields::Name:
			OrderBy(items, ascending, [](HistoryItem item) { return item.Item().Value().Name(); });
			break;
		case HistoryItemFields::Quantity:
			OrderBy(items, ascending, [](HistoryItem item) { return item.Quantity(); });
			break;
		case HistoryItemFields::Date:
			OrderBy(items, ascending, [](HistoryItem item) { return item.Date(); });
			break;
	}
}

void Sorter::Sort(std::vector<ItemSource>& items, ItemSourceFields field, bool ascending)
{
	switch (field)
	{
		case ItemSourceFields::Name:
			OrderBy(items, ascending, [](ItemSource item) { return item.Source().Value().Name(); });
			break;
		case ItemSourceFields::Price:
			OrderBy(items, ascending, [](ItemSource item) { return item.Price(); });
			break;
	}
}

void Sorter::Sort(std::vector<Item>& items, ItemFields field, bool ascending)
{
	switch (field)
	{
		case ItemFields::Name:
			OrderBy(items, ascending, [](Item item) { return item.Name(); });
			break;
		case ItemFields::Category:
			OrderBy(items, ascending, [](Item item) { return item.Category().Value().Name(); });
			break;
	}
}
