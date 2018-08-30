#pragma once
template <class TData>
class ProxyBase
{
protected:
	std::shared_ptr<QueryDispatcher> _queryDispatcher;
public:

	ProxyBase(const std::shared_ptr<QueryDispatcher>& queryDispatcher)
		: _queryDispatcher(queryDispatcher)
	{
	}

	virtual ~ProxyBase() = default;
	virtual TData Value() const = 0;
};