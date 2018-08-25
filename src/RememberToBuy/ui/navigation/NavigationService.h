#pragma once
#include <functional>
#include "logger/ILogger.h"
#include <Hypodermic/Container.h>
#include "ui/ViewBase.h"
#include "ui/ICanReset.h"
#include "Utilities.h"
#include <stack>
#include "ui/IViewModel.h"

class NavigationService
{
private:
	std::shared_ptr<IView> _currentView;
	std::shared_ptr<ILogger> _logger;
	std::shared_ptr<Hypodermic::Container> _container;
	std::stack<std::shared_ptr<IView>> _history;

public:
	NavigationService(const std::shared_ptr<Hypodermic::Container>& container,
	                  const std::shared_ptr<ILogger>& logger): _logger(logger), _container(container)
	{
	}

	template <class TViewModel, class = IsBaseOf<TViewModel, IViewModel>>
	void GoTo(std::function<void(std::shared_ptr<TViewModel>)> callback, bool pushCurrentToHistory = true)
	{
		std::shared_ptr<IViewModel> currentViewModel = _container->resolve<TViewModel>();

		Reset(currentViewModel);
		callback(std::static_pointer_cast<TViewModel>(currentViewModel));

		if (pushCurrentToHistory && _currentView != nullptr)
		{
			_history.push(_currentView);
			_logger->Debug("Pushed " + _currentView->Name() + " to history stack");
		}

		_currentView = _container->resolve<ViewBase<TViewModel>>();
		_logger->Debug("Navigated to " + _currentView->Name());
	}

	template <class TViewModel, class = IsBaseOf<TViewModel, IViewModel>>
	void Reset(std::shared_ptr<TViewModel> viewModel)
	{
		std::shared_ptr<ICanReset> canReset = std::dynamic_pointer_cast<ICanReset>(viewModel);
		if (canReset)
		{
			canReset->Reset();
			_logger->Debug("Reset " + viewModel->Name());
		}
	}

	template <class TViewModel, class = IsBaseOf<TViewModel, IViewModel>>
	void GoTo()
	{
		GoTo<TViewModel>([](std::shared_ptr<TViewModel> vm)
		{
			//
		});
	}

	void GoBack()
	{
		if (_history.empty())
		{
			_logger->Warn("History stack is empty");
		}
		else
		{
			_currentView = _history.top();
			_history.pop();
			_logger->Debug("Navigated back to " + _currentView->Name());
		}
	}


	bool CanGoBack() const
	{
		return !_history.empty();
	}

	std::shared_ptr<IView> CurrentView() const { return _currentView; }
};
