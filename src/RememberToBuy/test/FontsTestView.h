#pragma once
#include <imgui.h>
#include <string>
#include "ui/ITestView.h"
#include "Fonts.h"

class FontsTestView : public ITestView
{
public:
	std::string Name() const override
	{
		return "FontsTestVuiew";
	}

	void Render() override
	{
		ImGui::Begin("Test: Fonts");

		Text("Fonts::RobotoRegular_Title " ICON_FA_SHOPPING_CART, Fonts::RobotoRegular_Title);
		Text("Fonts::RobotoRegular_Normal " ICON_FA_CART_PLUS, Fonts::RobotoRegular_Normal);

		Text("Fonts::RobotoLight_Title1 " ICON_FA_MINUS_CIRCLE, Fonts::RobotoLight_Title1);
		Text("Fonts::RobotoLight_Title2 " ICON_FA_QUESTION_CIRCLE, Fonts::RobotoLight_Title2);

		Text("Fonts::RobotoBold_Normal " ICON_FA_EXCLAMATION_CIRCLE, Fonts::RobotoBold_Normal);

		Text("Fonts::FontAwesome5_Title " ICON_FA_EXCLAMATION_CIRCLE ICON_FA_SHOPPING_CART ICON_FA_CART_PLUS
		     ICON_FA_MINUS_CIRCLE ICON_FA_EXCLAMATION_CIRCLE, Fonts::FontAwesome5_Title);

		ImGui::End();
	}

	void Text(std::string text, const Fonts& font)
	{
		ImGui::PushFont(font);
		ImGui::Text(text.c_str());
		ImGui::PopFont();
	}
};
