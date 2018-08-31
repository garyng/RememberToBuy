#pragma once
#include "models/Source.h"
#include "ProxyBase.h"
#include "query/GetSourceById.h"

class SourceProxy : public ProxyBase<Source>
{
private:
	int _id{};
public:

	SourceProxy(const std::shared_ptr<QueryDispatcher>& queryDispatcher, const int id)
		: ProxyBase<Source>(queryDispatcher),
		  _id(id)
	{
	}

	SourceProxy()
	{
	}

	Source Value() const override
	{
		return _queryDispatcher->Dispatch<Source>(GetSourceById{_id});
	}
};
