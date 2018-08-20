#pragma once
#include <vector>
#include <imgui.h>
#include "IView.h"
#include "ITestView.h"

class Renderer
{
private:
	std::vector<std::shared_ptr<IView>> _views;
	std::vector<std::shared_ptr<ITestView>> _testViews;

public:
	explicit Renderer(const std::vector<std::shared_ptr<IView>>& views,
	                  const std::vector<std::shared_ptr<ITestView>>& testViews)
		: _views(views), _testViews(testViews)
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
			// todo: render current
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
