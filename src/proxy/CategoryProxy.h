#pragma once
#include "ProxyBase.h"
#include "models/Category.h"
#include "query/QueryDispatcher.h"
#include "query/GetCategoryById.h"


class CategoryProxy : public ProxyBase<Category>
{
private:
	int _id{};

public:


	CategoryProxy(const std::shared_ptr<QueryDispatcher>& queryDispatcher, const int id)
		: ProxyBase<Category>(queryDispatcher),
		  _id(id)
	{
	}

	CategoryProxy()
	{
	}

	Category Value() const override
	{
		return _queryDispatcher->Dispatch<Category>(GetCategoryById{_id});
	}
};
