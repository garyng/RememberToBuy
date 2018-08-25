#pragma once
#include "ui/IView.h"
#include "ui/ViewBase.h"
#include "CartViewModel.h"

class CartView : public ViewBase<CartViewModel>
{
public:
	CartView(const std::shared_ptr<CartViewModel>& viewModel, const std::shared_ptr<ILogger>& logger);
	std::string Name() const override;
	void Render() override;
};
