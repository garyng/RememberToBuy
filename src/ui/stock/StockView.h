#pragma once
#include "ui/ViewBase.h"
#include "StockViewModel.h"

class StockView : public ViewBase<StockViewModel>
{
public:
	StockView(const std::shared_ptr<StockViewModel>& viewModel, const std::shared_ptr<ILogger>& logger);
	std::string Name() const override;
	void Render() override;
};
