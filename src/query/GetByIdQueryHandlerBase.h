#pragma once
#include "GetById.h"
#include "proxy/ProxyFactory.h"

template <class TQuery, class TResult, class TStorage,
          class = IsBaseOf<TQuery, GetById>,
          class = IsBaseOf<TStorage, IStorage>>
class GetByIdQueryHandlerBase : public IQueryHandler<TQuery, TResult>
{
private:
	std::shared_ptr<TStorage> _storage;
	std::shared_ptr<ProxyFactory> _proxy;
public:
	GetByIdQueryHandlerBase(const std::shared_ptr<TStorage>& storage, const std::shared_ptr<ProxyFactory>& proxyFactory)
		: _storage(storage),
		_proxy(proxyFactory)
	{
	}

	TResult Handle(TQuery parameter) override
	{
		using namespace coveo::linq;
		if (_storage->Data().empty())
		{
			// todo: handle when storage is empty
			return TResult{};
		}
		TResult result = _storage->Data()
			| first([&](TResult item)
			{
				return item.Id() == parameter.Id;
			});
		_proxy->Apply(result);
		return result;
	}
};
