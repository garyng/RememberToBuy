#include "stdafx.h"
#include "GetSourceByIdQueryHandler.h"

GetSourceByIdQueryHandler::GetSourceByIdQueryHandler(const std::shared_ptr<SourceStorage>& storage,
                                                     const std::shared_ptr<ProxyFactory>& proxyFactory):
	GetByIdQueryHandlerBase<GetSourceById, Source, SourceStorage>(storage, proxyFactory)
{
}
