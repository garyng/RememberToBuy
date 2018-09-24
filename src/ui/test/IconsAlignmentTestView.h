#pragma once
#include <imgui.h>
#include <IconsFontAwesome5.h>
#include "ui/ITestView.h"
#include "Utilities.h"
#include "imgui/imgui_custom.h"

class IconAlignmentTestView : public ITestView
{
public:
	std::string Name() const override
	{
		return NAMEOF(IconAlignmentTestView);
	}

	void Render() override
	{
		ImGui::Begin("Test: Icon alignment");
		
		ImGui::Text(ICON_FA_HISTORY " ICON_FA_HISTORY");
		ImGui::Text(ICON_FA_USER_TIE " ICON_FA_USER_TIE");
		ImGui::Text(ICON_FA_SEARCH_PLUS " ICON_FA_SEARCH_PLUS");
		ImGui::Text(ICON_FA_LIFE_RING " ICON_FA_LIFE_RING");
		ImGui::Text(ICON_FA_SHARE " ICON_FA_SHARE");
		ImGui::Text(ICON_FA_ALIGN_JUSTIFY " ICON_FA_ALIGN_JUSTIFY");
		ImGui::Text(ICON_FA_BATTERY_THREE_QUARTERS " ICON_FA_BATTERY_THREE_QUARTERS");
		ImGui::Text(ICON_FA_OBJECT_UNGROUP " ICON_FA_OBJECT_UNGROUP");

		ImGui::Separator();

		ImGui::TextBoldNormal(ICON_FA_HISTORY " ICON_FA_HISTORY");
		ImGui::TextBoldNormal(ICON_FA_USER_TIE " ICON_FA_USER_TIE");
		ImGui::TextBoldNormal(ICON_FA_SEARCH_PLUS " ICON_FA_SEARCH_PLUS");
		ImGui::TextBoldNormal(ICON_FA_KEYBOARD " ICON_FA_KEYBOARD");

		ImGui::Separator();

		ImGui::TextLightTitle1(ICON_FA_HISTORY " ICON_FA_HISTORY");
		ImGui::TextLightTitle1(ICON_FA_USER_TIE " ICON_FA_USER_TIE");
		ImGui::TextLightTitle1(ICON_FA_SEARCH_PLUS " ICON_FA_SEARCH_PLUS");
		ImGui::TextLightTitle1(ICON_FA_UNIVERSAL_ACCESS " ICON_FA_UNIVERSAL_ACCESS");
		ImGui::TextLightTitle1(ICON_FA_DICE_ONE " ICON_FA_DICE_ONE");
		ImGui::TextLightTitle1(ICON_FA_KEYBOARD " ICON_FA_KEYBOARD");

		ImGui::Separator();

		ImGui::TextLightTitle2(ICON_FA_HISTORY " ICON_FA_HISTORY");
		ImGui::TextLightTitle2(ICON_FA_USER_TIE " ICON_FA_USER_TIE");;
		ImGui::TextLightTitle2(ICON_FA_DICE_ONE " ICON_FA_DICE_ONE");
		ImGui::TextLightTitle2(ICON_FA_KEYBOARD " ICON_FA_KEYBOARD");

		ImGui::Separator();

		ImGui::TextRegularTitle(ICON_FA_HISTORY " ICON_FA_HISTORY");
		ImGui::TextRegularTitle(ICON_FA_USER_TIE " ICON_FA_USER_TIE");
		ImGui::TextRegularTitle(ICON_FA_SEARCH_PLUS " ICON_FA_SEARCH_PLUS");

		ImGui::End();
	}
};
