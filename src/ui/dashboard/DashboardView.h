#pragma once
#include "ui/ViewBase.h"
#include "DashboardViewModel.h"

class DashboardView : public ViewBase<DashboardViewModel>
{
public:
	DashboardView(const std::shared_ptr<DashboardViewModel>& viewModel, const std::shared_ptr<ILogger>& logger)
		: ViewBase<DashboardViewModel>(viewModel, logger)
	{
	}

	std::string Name() const override
	{
		return NAMEOF(DashboardView);
	}

	void Render() override;
};
 