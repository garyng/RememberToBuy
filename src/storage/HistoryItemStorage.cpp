#include "stdafx.h"
#include "HistoryItemStorage.h"

HistoryItemStorage::HistoryItemStorage(const std::shared_ptr<ILogger>& logger): JsonStorage<HistoryItem>(logger)
{
}

std::string HistoryItemStorage::Filename() const
{
	return NAMEOF(HistoryItem)".json";
}

std::vector<HistoryItem> HistoryItemStorage::DefaultData() const
{
	return std::vector<HistoryItem>
	{
		{0, 9, 54, 2, 82.8205242035075, "8/31/2018 Friday 8:26:14 AM"},
		{1, 22, 73, 1, 1.55422682713448, "9/1/2018 Saturday 3:59:08 AM"},
		{2, 24, 62, 4, 7.82047952097863, "9/1/2018 Saturday 1:24:58 AM"},
		{3, 22, 73, 3, 81.490485563637, "9/1/2018 Saturday 1:15:52 AM"},
		{4, 46, 93, 8, 35.2977862303601, "8/31/2018 Friday 7:21:15 AM"},
		{5, 12, 36, 2, 10.8572424295625, "8/31/2018 Friday 11:52:53 AM"},
		{6, 46, 4, 8, 1.52275915514806, "8/31/2018 Friday 7:36:29 AM"},
		{7, 8, 41, 1, 87.4966264658126, "8/31/2018 Friday 3:17:16 PM"},
		{8, 34, 52, 5, 43.3588084473083, "8/31/2018 Friday 7:35:41 PM"},
		{9, 5, 1, 9, 39.3230055353246, "8/31/2018 Friday 10:12:07 PM"},
		{10, 10, 6, 6, 64.4310303518693, "8/31/2018 Friday 9:52:24 PM"},
		{11, 13, 37, 4, 88.3877672186996, "8/31/2018 Friday 2:37:02 PM"},
		{12, 4, 20, 1, 25.7963656488789, "9/1/2018 Saturday 2:29:15 AM"},
		{13, 21, 12, 8, 14.4357753579671, "9/1/2018 Saturday 5:22:48 AM"},
		{14, 1, 35, 5, 20.7836731783038, "8/31/2018 Friday 5:38:15 PM"},
		{15, 20, 64, 7, 91.357128016817, "8/31/2018 Friday 9:58:53 AM"},
		{16, 12, 13, 9, 77.6724157126958, "8/31/2018 Friday 4:42:17 PM"},
		{17, 43, 55, 9, 66.9817414181222, "8/31/2018 Friday 1:53:29 PM"},
		{18, 39, 78, 8, 24.0242800912933, "8/31/2018 Friday 5:23:49 PM"},
		{19, 24, 31, 4, 28.8511148853466, "8/31/2018 Friday 6:05:52 AM"}
	};
}
