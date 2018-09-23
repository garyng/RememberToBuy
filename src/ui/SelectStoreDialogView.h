#pragma once
#include "ViewBase.h"
#include "SelectStoreDialogViewModel.h"

class SelectStoreDialogView : public ViewBase<SelectStoreDialogViewModel>
{
public:
	SelectStoreDialogView(const std::shared_ptr<SelectStoreDialogViewModel>& viewModel,
	                      const std::shared_ptr<ILogger>& logger);

	std::string Name() const override;

	void Render() override;
};
