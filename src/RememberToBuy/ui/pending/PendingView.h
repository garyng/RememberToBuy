#pragma once
#include "ui/ViewBase.h"
#include "PendingViewModel.h"

class PendingView : public ViewBase<PendingViewModel>
{
public:
	PendingView(const std::shared_ptr<PendingViewModel>& viewModel, const std::shared_ptr<ILogger>& logger);
	std::string Name() const override;
	void Render() override;
};
