#include "stdafx.h"
#include "CartItemStorage.h"

CartItemStorage::CartItemStorage(const std::shared_ptr<ILogger>& logger): JsonStorage<CartItem>(logger)
{
}

std::string CartItemStorage::Filename() const
{
	return NAMEOF(CartItem)".json";
}

std::vector<CartItem> CartItemStorage::DefaultData() const
{
	return std::vector<CartItem>
	{
		{0, 44, 1, 0},
		{1, 20, 7, 1},
		{2, 25, 1, 2},
		{3, 19, 6, 6},
		{4, 42, 3, 2},
		{5, 2, 5, 7},
		{6, 40, 3, 7},
		{7, 39, 7, 6},
		{8, 9, 0, 2},
		{9, 45, 10, 2}
	};
}
