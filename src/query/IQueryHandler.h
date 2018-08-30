#pragma once
template <class TQuery, class TResult>
class IQueryHandler
{
public:
	virtual ~IQueryHandler() = default;
	virtual TResult Handle(TQuery parameter) = 0;
};

