#pragma once
#include <string>

class IView
{
public:
	virtual ~IView() = default;
	virtual std::string Name() const = 0;
	virtual void Render() = 0;
};
