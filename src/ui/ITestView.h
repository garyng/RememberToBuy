#pragma once
#include "IView.h"

class ITestView : public IView
{
protected:
	bool _isVisible{false};
public:
	bool IsVisible() const { return _isVisible; }
	void IsVisible(bool value) { _isVisible = value; }
};
