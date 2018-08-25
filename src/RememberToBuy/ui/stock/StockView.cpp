#include "stdafx.h"
#include "StockView.h"

StockView::StockView(const std::shared_ptr<StockViewModel>& viewModel,
                     const std::shared_ptr<ILogger>& logger): ViewBase<StockViewModel>(viewModel, logger)
{
}

std::string StockView::Name() const
{
	return NAMEOF(StockView);
}

void StockView::Render()
{
	ImGui::BeginDefaultCenteredResizableWindow("Stock");
	RenderGoBackButton();

	ImGui::End();
}
