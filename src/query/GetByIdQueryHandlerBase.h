#pragma once
#include "GetById.h"

template <class TQuery, class TResult, class TStorage,
	class = IsBaseOf<TQuery, GetById>,
	class = IsBaseOf<TStorage, IStorage>>
	class GetByIdQueryHandlerBase : public IQueryHandler<TQuery, TResult>
{
private:
	std::shared_ptr<TStorage> _storage;
public:
	GetByIdQueryHandlerBase(const std::shared_ptr<TStorage>& storage)
		: _storage(storage)
	{
	}

	TResult Handle(TQuery parameter) override
	{
		using namespace coveo::linq;
		return _storage->Data()
			| first([&](TResult item)
		{
			return item.Id() == parameter.Id;
		});
	}
};
