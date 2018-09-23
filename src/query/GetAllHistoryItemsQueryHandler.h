#pragma once
#include "GetAllHistoryItems.h"
#include "storage/HistoryItemStorage.h"
#include "proxy/ProxyFactory.h"

class GetAllHistoryItemsQueryHandler : public IQueryHandler<GetAllHistoryItems, std::vector<HistoryItem>>
{
private:
	std::shared_ptr<HistoryItemStorage> _historyItemStorage;
	std::shared_ptr<ProxyFactory> _proxyFactory;
public:

	GetAllHistoryItemsQueryHandler(const std::shared_ptr<HistoryItemStorage>& historyItemStorage,
	                               const std::shared_ptr<ProxyFactory>& proxyFactory);

	std::vector<HistoryItem> Handle(GetAllHistoryItems parameter) override;
};
