#include "stdafx.h"
#include "CartView.h"
#include "imgui_internal.h"

CartView::CartView(const std::shared_ptr<CartViewModel>& viewModel,
                   const std::shared_ptr<ILogger>& logger): ViewBase<CartViewModel>(viewModel, logger)
{
}

std::string CartView::Name() const
{
	return NAMEOF(CartView);
}

void CartView::Render()
{
	ImGui::BeginDefaultCenteredResizableWindow("Cart");
	RenderGoBackButton();
	ImGui::End();
}
