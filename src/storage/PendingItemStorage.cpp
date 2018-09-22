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
		{0, 49, 65},
		{1, 4, 36},
		{2, 14, 86},
		{3, 18, 29},
		{4, 6, 94},
		{5, 30, 63},
		{6, 35, 4},
		{7, 19, 96},
		{8, 3, 44},
		{9, 34, 27},
		{10, 44, 28},
		{11, 35, 46},
		{12, 11, 26},
		{13, 42, 45},
		{14, 33, 3},
		{15, 4, 61},
		{16, 22, 92},
		{17, 42, 60},
		{18, 1, 78},
		{19, 24, 70}

	};
}
