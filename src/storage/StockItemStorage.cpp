#include "stdafx.h"
#include "StockItemStorage.h"

StockItemStorage::StockItemStorage(const std::shared_ptr<ILogger>& logger): JsonStorage<StockItem>(logger)
{
}

std::string StockItemStorage::Filename() const
{
	return NAMEOF(StockItem)".json";
}

std::vector<StockItem> StockItemStorage::DefaultData() const
{
	return std::vector<StockItem>
	{
		{0, 50, 13},
		{1, 73, 36},
		{2, 5, 8},
		{3, 5, 22},
		{4, 84, 28},
		{5, 42, 43},
		{6, 34, 0},
		{7, 11, 35},
		{8, 95, 31},
		{9, 13, 1},
		{10, 100, 46},
		{11, 62, 4},
		{12, 84, 0},
		{13, 17, 40},
		{14, 19, 39},
		{15, 93, 14},
		{16, 96, 49},
		{17, 78, 31},
		{18, 56, 48},
		{19, 41, 3}
	};
}
