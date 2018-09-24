#pragma once
#include "SelectItemViewModel.h"

class SelectItemView : public ViewBase<SelectItemViewModel>
{
public:
	SelectItemView(const std::shared_ptr<SelectItemViewModel>& viewModel, const std::shared_ptr<ILogger>& logger);

	std::string Name() const override
	{
		return NAMEOF(SelectItemView);
	}

	void Render() override;
	void RenderSearchNoResult();
	void RenderNoItems();
	void RenderMaster();
	void RenderDetails();
	void RenderSortByButtons();
	void RenderSearchBox();

	void RenderSelectButton();

};
