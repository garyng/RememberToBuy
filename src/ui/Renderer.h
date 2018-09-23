#pragma once
#include <vector>
#include <imgui.h>
#include "IView.h"
#include "ITestView.h"
#include "navigation/NavigationService.h"
#include "dialog/DialogService.h"

class Renderer
{
private:
	std::vector<std::shared_ptr<IView>> _views;
	std::vector<std::shared_ptr<ITestView>> _testViews;
	std::shared_ptr<NavigationService> _navigationService;
	std::shared_ptr<DialogService> _dialogService;

public:
	explicit Renderer(const std::vector<std::shared_ptr<IView>>& views,
	                  const std::vector<std::shared_ptr<ITestView>>& testViews,
	                  const std::shared_ptr<NavigationService>& navigationService,
	                  const std::shared_ptr<DialogService>& dialogService)
		: _views(views), _testViews(testViews), _navigationService(navigationService), _dialogService(dialogService)
	{
	}

	void Render() const
	{
		static bool showAllViews{false};

		if (ImGui::BeginMainMenuBar())
		{
			if (ImGui::BeginMenu("Debug"))
			{
				ImGui::Text("Views");

				ImGui::Checkbox("Show all views", &showAllViews);

				ImGui::Separator();

				ImGui::Text("Test views");

				RenderShowAllTestViewsButton();
				RenderShowTestViewButton();

				ImGui::EndMenu();
			}

			RenderAboutMenu();

			ImGui::EndMainMenuBar();
		}

		RenderVisibleTestViews();

		if (showAllViews)
		{
			for (const auto& view : _views)
			{
				view->Render();
			}
		}
		else
		{
			_navigationService->CurrentView()->Render();
			if (_dialogService->CurrentDialogView().has_value())
			{
				_dialogService->CurrentDialogView().value()->Render();
			}
		}
	}

	void RenderShowAllTestViewsButton() const
	{
		if (ImGui::FullWidthButton("Show all test views"))
		{
			for (const auto& testView : _testViews)
			{
				testView->IsVisible(true);
			}
		}
	}

	void RenderShowTestViewButton() const
	{
		for (const auto& testView : _testViews)
		{
			bool isVisisble = testView->IsVisible();
			ImGui::Checkbox(testView->Name().c_str(), &isVisisble);
			testView->IsVisible(isVisisble);
		}
	}

	void RenderVisibleTestViews() const
	{
		for (const auto& testView : _testViews)
		{
			if (testView->IsVisible())
			{
				testView->Render();
			}
		}
	}

	void RenderAboutMenu() const
	{
		if (ImGui::BeginMenu("About"))
		{
			ImGui::Text("Made for TDS2141");
			ImGui::EndMenu();
		}
	}
};
