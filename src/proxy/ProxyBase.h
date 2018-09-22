#pragma once
template <class TData>
class ProxyBase
{
protected:
	std::shared_ptr<QueryDispatcher> _queryDispatcher;
	bool _initialized{false}; // is _queryDispatcher available?
public:

	ProxyBase(const std::shared_ptr<QueryDispatcher>& queryDispatcher)
		: _queryDispatcher(queryDispatcher), _initialized(true)
	{
		// when being initialize in query/command handlers
	}

	ProxyBase()
	{
		// when used within model objects
	}

	virtual ~ProxyBase() = default;
	virtual TData Value() const = 0;

	operator bool() const { return _initialized; }
	operator TData() const { return Value(); }
};
