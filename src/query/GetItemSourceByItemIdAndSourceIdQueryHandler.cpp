#include "stdafx.h"
#include "GetItemSourceByItemIdAndSourceIdQueryHandler.h"

GetItemSourceByItemIdAndSourceIdQueryHandler::GetItemSourceByItemIdAndSourceIdQueryHandler(
	const std::shared_ptr<ItemSourceStorage>& itemSourceStorage, const std::shared_ptr<ProxyFactory>& proxyFactory):
	_storage(itemSourceStorage),
	_proxy(proxyFactory)
{
}

ItemSource GetItemSourceByItemIdAndSourceIdQueryHandler::Handle(GetItemSourceByItemIdAndSourceId parameter)
{
	using namespace coveo::linq;
	ItemSource result = _storage->Data()
		| first([&](ItemSource item)
		{
			return item.ItemId() == parameter.ItemId && item.SourceId() == parameter.SourceId;
		});
	_proxy->Apply(result);
	return result;
}
