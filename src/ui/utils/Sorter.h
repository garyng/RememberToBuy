#pragma once
#include "models/CartItem.h"

class Sorter
{
public:

	static void Sort(std::vector<CartItem>& items, CartItemFields field, bool ascending = true);

private:
	template <class TData, class Selector>
	static void OrderBy(std::vector<TData>& items, bool ascending, Selector&& selector)
	{
		using namespace coveo::linq;

		if (ascending)
		{
			items = items
				| order_by(std::forward<Selector>(selector))
				| where([](auto item) { return true; })
				| to_vector();
		}
		else
		{
			items = items
				| order_by_descending(std::forward<Selector>(selector))
				| where([](auto item) { return true; })
				| to_vector();
		}
	}
};
