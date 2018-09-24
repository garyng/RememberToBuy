#pragma once
#include <Hypodermic/Container.h>

class QueryDispatcher
{
private:
	const std::shared_ptr<Hypodermic::Container> _container{};

public:
	QueryDispatcher(const std::shared_ptr<Hypodermic::Container>& container) : _container(container)
	{
	}

	template <class TResult, class TQuery>
	TResult Dispatch(TQuery param)
	{
		std::shared_ptr<IQueryHandler<TQuery, TResult>> handler = _container->resolve<IQueryHandler<TQuery, TResult>>();
		return handler->Handle(param);
	}
};
