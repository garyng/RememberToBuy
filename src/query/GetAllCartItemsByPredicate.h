#pragma once
#include "models/CartItem.h"
#include "GetAllByPredicate.h"

class GetAllCartItemsByPredicate : public GetAllByPredicate<CartItem>
{
public:
	GetAllCartItemsByPredicate(const std::function<bool(const CartItem&)>& predicate)
		: GetAllByPredicate<CartItem>(predicate)
	{
	}
};
