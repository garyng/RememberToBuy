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
		{0, 32, 7, 2},
		{1, 43, 7, 9},
		{2, 17, 3, 8},
		{3, 6, 7, 6},
		{4, 10, 8, 6},
		{5, 20, 9, 9},
		{6, 25, 10, 5},
		{7, 19, 3, 0},
		{8, 38, 10, 2},
		{9, 15, 9, 2}
	};
}
