#pragma once
#include <imgui.h>
#include "ui/ITestView.h"
#include "ui/IViewModel.h"
#include "ui/navigation/NavigationService.h"
#include "imgui/imgui_custom.h"
#include "ui/pending/PendingViewModel.h"
#include "ui/cart/CartViewModel.h"
#include "ui/history/HistoryViewModel.h"
#include "ui/stock/StockViewModel.h"

class NavigationTestView : public ITestView
{
private:

	std::shared_ptr<NavigationService> _navigationService;

public:
	NavigationTestView(const std::shared_ptr<NavigationService>& navigationService)
		: _navigationService(navigationService)
	{
	}

	std::string Name() const override
	{
		return "NavigationTestView";
	}

	void Render() override
	{
		ImGui::Begin("Test: Navigation service");

		RenderNavigateToButton<CartViewModel>();
		RenderNavigateToButton<PendingViewModel>();
		RenderNavigateToButton<HistoryViewModel>();
		RenderNavigateToButton<StockViewModel>();

		if (ImGui::FullWidthButton(ICON_FA_ARROW_LEFT " Go back"))
		{
			_navigationService->GoBack();
		}

		ImGui::End();
	}

	template <class TViewModel, class = IsBaseOf<TViewModel, IViewModel>>
	void RenderNavigateToButton()
	{
		if (ImGui::FullWidthButton("Navigate to '" + std::string(typeid(TViewModel).name()) + "'"))
		{
			_navigationService->GoTo<TViewModel>();
		}
	}
};
