#include "stdafx.h"
#include "Sorter.h"
#include <coveo/linq.h>

void Sorter::Sort(std::vector<CartItem>& items, CartItemFields field, bool ascending)
{
	using namespace coveo::linq;

	OrderBy(items, ascending, [](CartItem item) { return item.Item().Value().Name(); });
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
