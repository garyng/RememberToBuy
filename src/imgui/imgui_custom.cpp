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

	void OkCancelPopupModel(std::string name, std::string icon, std::initializer_list<std::string> texts,
	                        std::function<void()> onOkClicked,
	                        std::string ok, std::string cancel, float buttonWidth)
	{
		OkCancelPopupModel(name, icon, texts, onOkClicked, []()
		{
		}, ok, cancel, buttonWidth);
	}

	void OkCancelPopupModel(std::string name, std::string icon, std::initializer_list<std::string> texts,
	                        std::function<void()> onOkClicked, std::function<void()> onCancelClicked,
	                        std::string ok, std::string cancel, float buttonWidth)
	{
		SetNextWindowPosCenter();
		if (BeginPopupModal(name.c_str(), nullptr, ImGuiWindowFlags_AlwaysAutoResize))
		{
			Text("");

			PushFont(Fonts::FontAwesome5_Title);
			Text(icon.c_str());
			PopFont();

			SameLine();

			BeginGroup();
			{
				for (const auto& text : texts)
				{
					Text(text.c_str());
				}
			}
			EndGroup();


			float buttonStartX = GetWindowSize().x / 2 - buttonWidth;
			SetCursorPosX(buttonStartX);

			if (Button(ok.c_str(), ImVec2{buttonWidth, 0}))
			{
				onOkClicked();
				CloseCurrentPopup();
			}
			SameLine();
			if (Button(cancel.c_str(), ImVec2{buttonWidth, 0}))
			{
				onCancelClicked();
				CloseCurrentPopup();
			}

			EndPopup();
		}
	}

	void TextBoldNormal(std::string text)
	{
		PushFont(Fonts::RobotoBold_Normal);
		Text(text.c_str());
		PopFont();
	}

	void TextLightTitle1(std::string text)
	{
		PushFont(Fonts::RobotoLight_Title1);
		Text(text.c_str());
		PopFont();
	}

	void TextLightTitle2(std::string text)
	{
		PushFont(Fonts::RobotoLight_Title2);
		Text(text.c_str());
		PopFont();
	}

	void TextRegularTitle(std::string text)
	{
		PushFont(Fonts::RobotoRegular_Title);
		Text(text.c_str());
		PopFont();
	}

	bool FullWidthInputInt(std::string label, int& value)
	{
		PushItemWidth(-1);
		bool isValueChanged = InputInt(label.c_str(), &value);
		PopItemWidth();
		return isValueChanged;
	}
}
