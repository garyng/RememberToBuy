#pragma once
#include <string>

class IView
{

public:
	virtual ~IView() = default;
	std::string virtual Name() const = 0;
	void virtual Render() = 0;
};
