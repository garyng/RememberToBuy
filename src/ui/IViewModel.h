#pragma once
#include <string>

class IViewModel
{
public:
	virtual ~IViewModel() = default;
	virtual std::string Name() = 0;
};
