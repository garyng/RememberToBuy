#pragma once
#include <vector>
#include <imgui.h>
#include <IconsFontAwesome5.h>
#include "imgui/imgui_custom.h"
#include "Utilities.h"
#include "ui/ITestView.h"
#include "ui/ICanReset.h"

class ICanResetTestView : public ITestView
{
private:
	std::vector<std::shared_ptr<ICanReset>> _resettables;
public:

	ICanResetTestView(const std::vector<std::shared_ptr<ICanReset>>& resettables)
		: _resettables(resettables)
	{
	}

	std::string Name() const override
	{
		return NAMEOF(ICanResetTestView);
	}

	void Render() override
	{
		ImGui::Begin("Test: ICanReset");
		RenderResetButton();
		ImGui::End();
	}

	void RenderResetButton() const
	{
		for (const auto& canReset : _resettables)
		{
			std::string name = std::string(typeid(*canReset).name());
			std::string label = "Reset " + name;
			std::string popupName = "Are you sure?##" + name;
			if (ImGui::FullWidthButton(label))
			{
				ImGui::OpenPopup(popupName.c_str());
			}

			ImGui::OkCancelPopupModel(popupName.c_str(), ICON_FA_EXCLAMATION_CIRCLE,
			                          {
				                          "Resetting " + name,
				                          "Are you sure?"
			                          }, [&]()
			                          {
				                          canReset->Reset();
			                          }, "Yes", "No");
		}
	}
};
