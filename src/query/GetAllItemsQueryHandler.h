#pragma once
#include "GetAllItems.h"
#include "proxy/ProxyFactory.h"
#include "storage/ItemStorage.h"

class GetAllItemsQueryHandler : public IQueryHandler<GetAllItems, std::vector<Item>>
{
private:
	std::shared_ptr<ItemStorage> _itemStorage;
	std::shared_ptr<ProxyFactory> _proxyFactory;
public:
	GetAllItemsQueryHandler(const std::shared_ptr<ItemStorage>& itemStorage,
	                        const std::shared_ptr<ProxyFactory>& proxyFactory);

	std::vector<Item> Handle(GetAllItems parameter) override;
};
