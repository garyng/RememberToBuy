#pragma once
#include "models/ItemSource.h"
#include "GetBestSourceByItemId.h"
#include "storage/ItemSourceStorage.h"
#include "proxy/ProxyFactory.h"

class GetBestSourceByItemIdQueryHandler : public IQueryHandler<GetBestSourceByItemId, ItemSource>
{
private:
	std::shared_ptr<ItemSourceStorage> _itemSourceStorage;
	std::shared_ptr<ProxyFactory> _proxyFactory;
public:

	GetBestSourceByItemIdQueryHandler(const std::shared_ptr<ItemSourceStorage>& itemSourceStorage,
	                                  const std::shared_ptr<ProxyFactory>& proxyFactory);

	ItemSource Handle(GetBestSourceByItemId parameter) override;
};
