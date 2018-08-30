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
		{0, 8, 82, 0, 58.3555676235611, "8/29/2018 Wednesday 10:54:39 AM"},
		{1, 24, 68, 9, 44.9742851848594, "8/29/2018 Wednesday 3:46:48 PM"},
		{2, 1, 0, 0, 40.63372342318, "8/30/2018 Thursday 1:06:41 AM"},
		{3, 35, 96, 6, 42.590331818252, "8/30/2018 Thursday 12:40:15 AM"},
		{4, 17, 51, 2, 49.040500897933, "8/29/2018 Wednesday 4:03:36 PM"},
		{5, 4, 54, 7, 24.0212787664594, "8/29/2018 Wednesday 9:54:12 AM"},
		{6, 38, 60, 2, 88.8348630596115, "8/29/2018 Wednesday 9:01:22 PM"},
		{7, 37, 85, 3, 63.8491920185504, "8/29/2018 Wednesday 12:52:06 PM"},
		{8, 18, 87, 2, 38.6142547356963, "8/29/2018 Wednesday 6:42:00 PM"},
		{9, 30, 23, 2, 71.350845546625, "8/29/2018 Wednesday 2:45:13 PM"},
		{10, 3, 47, 0, 90.2446073332078, "8/29/2018 Wednesday 6:49:49 AM"},
		{11, 33, 53, 9, 16.410261514322, "8/29/2018 Wednesday 1:14:49 PM"},
		{12, 47, 19, 5, 76.6323837729322, "8/29/2018 Wednesday 10:10:44 AM"},
		{13, 21, 79, 5, 19.1598307272232, "8/29/2018 Wednesday 6:54:26 PM"},
		{14, 42, 69, 6, 86.4799651119299, "8/29/2018 Wednesday 9:32:42 AM"},
		{15, 24, 53, 4, 17.9853048687732, "8/29/2018 Wednesday 6:52:09 AM"},
		{16, 43, 30, 6, 75.687275369506, "8/29/2018 Wednesday 11:33:03 AM"},
		{17, 14, 12, 1, 8.81713281097688, "8/29/2018 Wednesday 1:01:29 PM"},
		{18, 10, 91, 5, 10.299833794264, "8/29/2018 Wednesday 11:43:09 AM"},
		{19, 8, 51, 9, 71.4098512406507, "8/29/2018 Wednesday 5:06:56 AM"}
	};
}
