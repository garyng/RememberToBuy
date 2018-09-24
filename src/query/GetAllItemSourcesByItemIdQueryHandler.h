#pragma once
#include "models/ItemSource.h"
#include "GetAllItemSourcesByItemId.h"
#include "proxy/ProxyFactory.h"
#include "storage/ItemSourceStorage.h"


class GetAllItemSourcesByItemIdQueryHandler : public IQueryHandler<GetAllItemSourcesByItemId, std::vector<ItemSource>>
{
private:
	std::shared_ptr<ItemSourceStorage> _itemSourceStorage;
	std::shared_ptr<ProxyFactory> _proxyFactory;

public:
	GetAllItemSourcesByItemIdQueryHandler(const std::shared_ptr<ItemSourceStorage>& itemSourceStorage,
	                                      const std::shared_ptr<ProxyFactory>& proxyFactory);

	std::vector<ItemSource> Handle(GetAllItemSourcesByItemId parameter) override;
};
