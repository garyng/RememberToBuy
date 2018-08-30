#include "stdafx.h"
#include "PendingItemStorage.h"

PendingItemStorage::PendingItemStorage(const std::shared_ptr<ILogger>& logger): JsonStorage<PendingItem>(logger)
{
}

std::string PendingItemStorage::Filename() const
{
	return NAMEOF(PendingItem)".json";
}

std::vector<PendingItem> PendingItemStorage::DefaultData() const
{
	return std::vector<PendingItem>
	{
		{0, 41, 56},
		{1, 2, 40},
		{2, 31, 38},
		{3, 47, 62},
		{4, 10, 32},
		{5, 6, 62},
		{6, 38, 35},
		{7, 33, 66},
		{8, 20, 60},
		{9, 7, 37},
		{10, 15, 48},
		{11, 29, 63},
		{12, 4, 95},
		{13, 28, 42},
		{14, 12, 52},
		{15, 48, 31},
		{16, 9, 29},
		{17, 49, 30},
		{18, 11, 37},
		{19, 6, 22}

	};
}
