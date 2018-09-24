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

	void BlankScreenPrompt(std::string icon, std::initializer_list<std::string> texts)
	{
		PushFont(Fonts::FontAwesome5_Title);
		ImVec2 iconSize = CalcTextSize(icon.c_str());
		PopFont();

		PushFont(Fonts::RobotoLight_Title2);

		std::vector<std::pair<std::string, ImVec2>> textsAndSizes{};

		float totalHeight = iconSize.y;
		for (const auto& text : texts)
		{
			ImVec2 textSize = CalcTextSize(text.c_str());
			totalHeight += textSize.y;
			textsAndSizes.emplace_back(text, textSize);
		}

		ImVec2 windowSize = GetWindowSize();

		// vertically centered
		float currentY = (windowSize.y - totalHeight) / 2;

		SetCursorPosY(currentY);

		PushFont(Fonts::FontAwesome5_Title);
		TextCenteredHorizontally(icon, iconSize);
		PopFont();

		for (const auto& textAndSize : textsAndSizes)
		{
			TextCenteredHorizontally(textAndSize.first, textAndSize.second);
		}

		PopFont();
	}

	void NoItemSelectedPrompt(std::string name)
	{
		BeginChild(name.c_str());

		BlankScreenPrompt(ICON_FA_HAND_POINT_LEFT, { "Select one item to check its details" });

		EndChild();
	}

	void TextCenteredHorizontally(std::string text)
	{
		TextCenteredHorizontally(text, CalcTextSize(text.c_str()));
	}

	void TextCenteredHorizontally(std::string text, ImVec2 size)
	{
		ImVec2 windowSize = GetWindowSize();
		float currentX = (windowSize.x - size.x) / 2;
		SetCursorPosX(currentX);
		Text(text.c_str());
	}

	void TextBoldNormal(std::string text)
	{
		PushFont(Fonts::RobotoBold_Normal);
		TextWrapped(text.c_str());
		PopFont();
	}

	void TextLightTitle1(std::string text)
	{
		PushFont(Fonts::RobotoLight_Title1);
		TextWrapped(text.c_str());
		PopFont();
	}

	void TextLightTitle2(std::string text)
	{
		PushFont(Fonts::RobotoLight_Title2);
		TextWrapped(text.c_str());
		PopFont();
	}

	void TextRegularTitle(std::string text)
	{
		PushFont(Fonts::RobotoRegular_Title);
		TextWrapped(text.c_str());
		PopFont();
	}

	bool FullWidthInputInt(std::string label, int& value, int minimum)
	{
		const int oldValue = value;
		PushItemWidth(-1);
		InputInt(label.c_str(), &value);
		if (value < minimum)
		{
			value = minimum;
		}

		bool isValueChanged = value != oldValue;

		PopItemWidth();
		return isValueChanged;
	}
}
