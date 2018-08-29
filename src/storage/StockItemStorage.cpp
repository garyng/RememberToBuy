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

		{0, 34, 25},
		{1, 10, 37},
		{2, 41, 29},
		{3, 14, 38},
		{4, 42, 47},
		{5, 76, 45},
		{6, 6, 16},
		{7, 57, 17},
		{8, 97, 21},
		{9, 31, 33},
		{10, 82, 26},
		{11, 36, 34},
		{12, 35, 41},
		{13, 43, 23},
		{14, 37, 18},
		{15, 41, 2},
		{16, 47, 46},
		{17, 3, 40},
		{18, 38, 41},
		{19, 22, 24}

	};
}
