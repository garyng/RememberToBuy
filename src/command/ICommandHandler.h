#pragma once
template <class TCommand>
class ICommandHandler
{
public:
	virtual ~ICommandHandler() = default;
	virtual void Handle(TCommand& parameter) = 0;
};
