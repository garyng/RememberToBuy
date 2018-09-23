#pragma once
#include "ui/ViewBase.h"
#include "CartViewModel.h"

class CartView : public ViewBase<CartViewModel>
{
public:
	CartView(const std::shared_ptr<CartViewModel>& viewModel, const std::shared_ptr<ILogger>& logger);
	std::string Name() const override;

	void Render() override;

	void RenderGoToPendingButton();

	void RenderSearchNoResults();

	void RenderNoCartItems();

	void RenderCartItemList();

	void RenderSortByButtons();

	void RenderSearchBox();

	void RenderCartItemDetails();
};
