#pragma once
#include <functional>

class IDialog
{
private:
	std::function<void()> _onClosed;
public:
	void OnClosedCommand() const { _onClosed(); }
	void OnClosed(std::function<void()> value) { _onClosed = value; }
};
