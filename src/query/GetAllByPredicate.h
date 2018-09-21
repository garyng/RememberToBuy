#pragma once
template <class TData>
class GetAllByPredicate
{
public:
	std::function<bool(TData)> predicate;

	GetAllByPredicate(const std::function<bool(const TData&)>& predicate)
		: predicate(predicate)
	{
	}
};