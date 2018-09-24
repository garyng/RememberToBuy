#include "stdafx.h"
#include "GetAllHistoryItemsQueryHandler.h"

GetAllHistoryItemsQueryHandler::GetAllHistoryItemsQueryHandler(
	const std::shared_ptr<HistoryItemStorage>& historyItemStorage, const std::shared_ptr<ProxyFactory>& proxyFactory):
	_historyItemStorage(historyItemStorage),
	_proxyFactory(proxyFactory)
{
}

std::vector<HistoryItem> GetAllHistoryItemsQueryHandler::Handle(GetAllHistoryItems parameter)
{
	std::vector<HistoryItem> historyItems = _historyItemStorage->Data();
	_proxyFactory->Apply(historyItems);
	return historyItems;
}
