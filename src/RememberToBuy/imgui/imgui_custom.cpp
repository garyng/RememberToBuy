#include "stdafx.h"
#include "imgui.h"
#include "imgui/imgui_custom.h"

namespace ImGui
{
	bool FullWidthButton(const std::string label)
	{
		return Button(label.c_str(), ImVec2(-1, 0));
	}
}
