#pragma once
#include <functional>

namespace ImGui
{
	bool FullWidthButton(const std::string& label);
	bool BeginDefaultCenteredWindow(const std::string& name);
	bool BeginDefaultCenteredResizableWindow(const std::string& name);
	bool BeginChildWithBottomSpace(std::string id, int lines);

	void OkCancelPopupModel(std::string name, std::string icon, std::initializer_list<std::string> texts,
	                        std::function<void()> onOkClicked,
	                        std::string ok = "Ok", std::string cancel = "Cancel",
	                        float buttonWidth = 60);

	void OkCancelPopupModel(std::string name, std::string icon, std::initializer_list<std::string> texts,
	                        std::function<void()> onOkClicked, std::function<void()> onCancelClicked,
	                        std::string ok = "Ok", std::string cancel = "Cancel",
	                        float buttonWidth = 60);
	void TextBoldNormal(std::string text);
	void TextLightTitle1(std::string text);
	void TextLightTitle2(std::string text);
	void TextRegularTitle(std::string text);

	bool FullWidthInputInt(std::string label, int& value, int minimum = 1);
}
