#pragma once
#include "GetByIdQueryHandlerBase.h"
#include "GetSourceById.h"
#include "storage/SourceStorage.h"

class GetSourceByIdQueryHandler : public GetByIdQueryHandlerBase<GetSourceById, Source, SourceStorage>
{
public:
	GetSourceByIdQueryHandler(const std::shared_ptr<SourceStorage>& storage,
	                          const std::shared_ptr<ProxyFactory>& proxyFactory);
};
