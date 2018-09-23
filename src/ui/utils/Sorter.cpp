#include "stdafx.h"
#include "Sorter.h"
#include <coveo/linq.h>

void Sorter::Sort(std::vector<CartItem>& items, CartItemFields field, bool ascending)
{
	switch (field)
	{
		case CartItemFields::Id:
			OrderBy(items, ascending, [](CartItem item) { return item.Id(); });
			break;
		case CartItemFields::Quantity:
			OrderBy(items, ascending, [](CartItem item) { return item.Quantity(); });
			break;
		case CartItemFields::Name:
			OrderBy(items, ascending, [](CartItem item) { return item.Item().Value().Name(); });
			break;
	}
}

void Sorter::Sort(std::vector<HistoryItem>& items, HistoryItemFields field, bool ascending)
{
	switch (field)
	{
		case HistoryItemFields::Id:
			OrderBy(items, ascending, [](HistoryItem item) { return item.Id(); });
			break;
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
