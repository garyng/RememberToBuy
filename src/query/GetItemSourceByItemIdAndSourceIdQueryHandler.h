#pragma once

#include <coveo/linq.h>
#include "models/ItemSource.h"
#include "query/IQueryHandler.h"
#include "storage/ItemSourceStorage.h"
#include "proxy/ProxyFactory.h"
#include "GetItemSourceByItemIdAndSourceId.h"

class GetItemSourceByItemIdAndSourceIdQueryHandler : public IQueryHandler<GetItemSourceByItemIdAndSourceId, ItemSource>
{
private:
	std::shared_ptr<ItemSourceStorage> _storage;
	std::shared_ptr<ProxyFactory> _proxy;

public:


	GetItemSourceByItemIdAndSourceIdQueryHandler(const std::shared_ptr<ItemSourceStorage>& itemSourceStorage,
	                                             const std::shared_ptr<ProxyFactory>& proxyFactory);

	ItemSource Handle(GetItemSourceByItemIdAndSourceId parameter) override;
};
