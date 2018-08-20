#pragma once
#include "ui/ViewBase.h"
#include "HistoryViewModel.h"

class HistoryView : public ViewBase<HistoryViewModel>
{
public:
	HistoryView(const std::shared_ptr<HistoryViewModel>& viewModel, const std::shared_ptr<ILogger>& logger);
	std::string Name() const override;
	void Render() override;
};
