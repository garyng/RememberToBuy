#pragma once
#include "ui/IView.h"
#include "ui/ViewBase.h"
#include "CartViewModel.h"

class CartView : public ViewBase<CartViewModel>
{
public:
	CartView(const std::shared_ptr<CartViewModel>& viewModel, const std::shared_ptr<ILogger>& logger);
	std::string Name() const override;

	void Render() override
	{
		ImGui::BeginDefaultCenteredResizableWindow("Cart");
		RenderGoBackButton();

		for (auto&& cartItem : _viewModel->CartItems())
		{
			ImGui::Selectable(cartItem.Item()->Value().Name().c_str());
		}

		ImGui::End();
	}
};
