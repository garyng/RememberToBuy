#include "stdafx.h"
#include "GetCategoryByIdQueryHandler.h"

GetCategoryByIdQueryHandler::GetCategoryByIdQueryHandler(const std::shared_ptr<CategoryStorage>& storage,
                                                         const std::shared_ptr<ProxyFactory>& proxyFactory):
	GetByIdQueryHandlerBase<GetCategoryById, Category, CategoryStorage>(storage, proxyFactory)
{
}
