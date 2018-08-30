#include "stdafx.h"
#include "CartView.h"

CartView::CartView(const std::shared_ptr<CartViewModel>& viewModel,
                   const std::shared_ptr<ILogger>& logger): ViewBase<CartViewModel>(viewModel, logger)
{
}

std::string CartView::Name() const
{
	return NAMEOF(CartView);
}