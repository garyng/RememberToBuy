#pragma once

namespace ImGui
{
	bool FullWidthButton(const std::string& label);
	bool BeginDefaultCenteredWindow(const std::string& name);
	bool BeginDefaultCenteredResizableWindow(const std::string& name);
	bool BeginChildWithBottomSpace(std::string id, int lines);
}
