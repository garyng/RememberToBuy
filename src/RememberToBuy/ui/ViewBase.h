#pragma once
#include "IView.h"
#include "Utilities.h"

class ViewModelBase;

template <class TViewModel, class = IsBaseOf<TViewModel, ViewModelBase>>
class ViewBase : public IView
{
protected:
	std::shared_ptr<TViewModel> _viewModel;
	std::shared_ptr<ILogger> _logger;

	void RenderGoBackButton()
	{
		if (_viewModel->CanGoBack())
		{
			if (ImGui::Selectable(ICON_FA_ARROW_LEFT " Back"))
			{
				_viewModel->GoBackCommand();
			}
		}
	}

public:
	ViewBase(const std::shared_ptr<TViewModel>& viewModel,
	         const std::shared_ptr<ILogger>& logger): _viewModel(viewModel), _logger(logger)
	{
	}
};
