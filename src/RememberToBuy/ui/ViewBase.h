#pragma once
#include "IView.h"
#include "IViewModel.h"

template <class TViewModel, class = IsBaseOf<TViewModel, IViewModel>>
class ViewBase : public IView
{
protected:
	std::shared_ptr<TViewModel> _viewModel;
	std::shared_ptr<ILogger> _logger;

public:
	ViewBase(const std::shared_ptr<TViewModel>& viewModel,
	         const std::shared_ptr<ILogger>& logger): _viewModel(viewModel), _logger(logger)
	{
	}
};
