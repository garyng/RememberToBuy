#pragma once
// https://www.fluentcpp.com/2018/05/18/make-sfinae-pretty-2-hidden-beauty-sfinae/
template <class TDerived, class TBase>
using IsBaseOf = std::enable_if_t<std::is_base_of_v<TBase, TDerived>>;

#define NAMEOF(type) #type