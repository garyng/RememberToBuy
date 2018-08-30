#include "stdafx.h"
#include "imgui.h"
#include "imgui/imgui_custom.h"

namespace ImGui
{
	bool FullWidthButton(const std::string& label)
	{
		return Button(label.c_str(), ImVec2(-1, 0));
	}

	bool BeginDefaultCenteredWindow(const std::string& name)
	{
		SetNextWindowPosCenter();
		return Begin(name.c_str(), nullptr,
		             ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoCollapse);
	}

	bool BeginDefaultCenteredResizableWindow(const std::string& name)
	{
		SetNextWindowPosCenter();
		return Begin(name.c_str(), nullptr, ImGuiWindowFlags_NoCollapse);
	}

	bool BeginChildWithBottomSpace(std::string id, int lines)
	{
		return BeginChild(id.c_str(), ImVec2{0, -lines * GetItemsLineHeightWithSpacing()});
	}
}
