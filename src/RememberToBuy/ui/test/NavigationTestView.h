#pragma once
#include <imgui.h>
#include <vector>
#include "ui/ITestView.h"
#include "ui/IViewModel.h"
#include "ui/navigation/NavigationService.h"
#include "imgui/imgui_custom.h"


class NavigationTestView : public ITestView
{
private:
	std::vector<std::shared_ptr<IViewModel>> _viewModels;
	std::shared_ptr<NavigationService> _navigationService;

public:
	NavigationTestView(const std::vector<std::shared_ptr<IViewModel>>& viewModels,
	                   const std::shared_ptr<NavigationService>& navigationService)
		: _viewModels(viewModels), _navigationService(navigationService)
	{
	}

	std::string Name() const override
	{
		return "NavigationTestView";
	}

	void Render() override
	{
		ImGui::Begin("Test: Navigation service");

		for (const auto& viewModel : _viewModels)
		{
			if (ImGui::FullWidthButton("Navigate to " + viewModel->Name()))
			{
				_navigationService->GoTo(viewModel);
				// todo: test all variants of GoTo

			}
		}

		if (ImGui::FullWidthButton(ICON_FA_ARROW_LEFT " Go back"))
		{
			_navigationService->GoBack();
		}

		ImGui::End();
	}
};
