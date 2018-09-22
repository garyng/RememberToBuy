#pragma once
#include <boost/format.hpp>

// https://www.fluentcpp.com/2018/05/18/make-sfinae-pretty-2-hidden-beauty-sfinae/
template <class TDerived, class TBase>
using IsBaseOf = std::enable_if_t<std::is_base_of_v<TBase, TDerived>>;

#define NAMEOF(type) #type

inline std::string formatCurrency(double price, std::string label = "")
{
	if (label == "")
	{
		return (boost::format("RM %1$.2f") % price).str();
	}
	return (boost::format("%1%: RM %2$.2f") % label % price).str();
}
