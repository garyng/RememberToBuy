#pragma once
#include "ui/ViewBase.h"
#include "SelectSourceViewModel.h"

class SelectSourceView : public ViewBase<SelectSourceViewModel>
{
public:
	SelectSourceView(const std::shared_ptr<SelectSourceViewModel>& viewModel, const std::shared_ptr<ILogger>& logger);

	std::string Name() const override;

	void RenderHeader();
	void Render() override;
	void RenderSearchNoResult();
	void RenderNoItems();
	void RenderSortByButtons();
	void RenderSearchBox();
	void RenderMaster();
	void RenderApplyButton();
	void RenderDetails();
};
