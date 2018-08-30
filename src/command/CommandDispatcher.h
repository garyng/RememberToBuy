#pragma once
#include <Hypodermic/Container.h>

class CommandDispatcher
{
private:
	const std::shared_ptr<Hypodermic::Container> _container{};
public:

	CommandDispatcher(const std::shared_ptr<Hypodermic::Container>& container) : _container(container)
	{
	}

	template <class TCommand>
	void Dispatch(TCommand& param)
	{
		std::shared_ptr<ICommandHandler<TCommand>> handler = _container->resolve<ICommandHandler<TCommand>>();
		handler->Handle(param);
	}
};
