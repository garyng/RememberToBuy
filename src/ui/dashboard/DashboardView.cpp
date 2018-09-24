#include "stdafx.h"
#include "DashboardView.h"

void DashboardView::Render()
{
	ImGui::BeginDefaultCenteredWindow("Dashboard");
	RenderGoBackButton();

	ImGui::PushFont(Fonts::RobotoLight_Title1);
	ImGui::TextCenteredHorizontally("Welcome back");
	ImGui::PopFont();

	ImGui::PushFont(Fonts::RobotoRegular_Small);
	ImGui::TextCenteredHorizontally("You have " + std::to_string(_viewModel->CartItemCount()) + " items in your cart");
	ImGui::PopFont();

	ImGui::Separator();
	ImGui::Spacing();

	if (ImGui::FullWidthButton(ICON_FA_SHOPPING_CART " Cart"))
	{
		_viewModel->GoToCartCommand();
	}
	if (ImGui::FullWidthButton(ICON_FA_HISTORY " History"))
	{
		_viewModel->GoToHistoryCommand();
	}
	ImGui::End();
}
