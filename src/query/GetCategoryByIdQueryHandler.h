#pragma once
#include "storage/CategoryStorage.h"
#include "GetByIdQueryHandlerBase.h"
#include "GetCategoryById.h"

class GetCategoryByIdQueryHandler : public GetByIdQueryHandlerBase<GetCategoryById, Category, CategoryStorage>
{
public:
	GetCategoryByIdQueryHandler(const std::shared_ptr<CategoryStorage>& storage,
	                            const std::shared_ptr<ProxyFactory>& proxyFactory);
};
