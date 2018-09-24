#pragma once
#include <imgui.h>
#include "ui/ITestView.h"
#include "ui/colors/Colors.h"

class ColorsTestView : public ITestView
{
public:
	std::string Name() const override
	{
		return "ColorsTestView";
	}
	void Render() override
	{
		ImGui::Begin("Test: Colors");

		ImGui::TextColored(Colors::DefaultWhite, "DefaultWhite");
		ImGui::TextColored(Colors::Red500, "Red500");
		ImGui::TextColored(Colors::Pink500, "Pink500");
		ImGui::TextColored(Colors::Purple500, "Purple500");
		ImGui::TextColored(Colors::DeepPurple500, "DeepPurple500");
		ImGui::TextColored(Colors::Indigo500, "Indigo500");
		ImGui::TextColored(Colors::Blue500, "Blue500");
		ImGui::TextColored(Colors::LightBlue500, "LightBlue500");
		ImGui::TextColored(Colors::Cyan500, "Cyan500");
		ImGui::TextColored(Colors::Teal500, "Teal500");
		ImGui::TextColored(Colors::Green500, "Green500");
		ImGui::TextColored(Colors::LightGreen500, "LightGreen500");
		ImGui::TextColored(Colors::Lime500, "Lime500");
		ImGui::TextColored(Colors::Yellow500, "Yellow500");
		ImGui::TextColored(Colors::Amber500, "Amber500");
		ImGui::TextColored(Colors::Orange500, "Orange500");
		ImGui::TextColored(Colors::DeepOrange500, "DeepOrange500");
		ImGui::TextColored(Colors::Brown500, "Brown500");
		ImGui::TextColored(Colors::Grey500, "Grey500");
		ImGui::TextColored(Colors::BlueGrey500, "BlueGrey500");

		ImGui::End();

	}
};
