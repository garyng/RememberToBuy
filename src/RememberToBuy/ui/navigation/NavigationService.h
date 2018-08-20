#pragma once
#include <functional>
#include "logger/ILogger.h"
#include <Hypodermic/Container.h>
#include "ui/ViewBase.h"

class NavigationService
{
private:
	std::shared_ptr<IView> _currentView;
	std::shared_ptr<ILogger> _logger;
	std::shared_ptr<Hypodermic::Container> _container;

public:
	NavigationService(const std::shared_ptr<Hypodermic::Container>& container,
	                  const std::shared_ptr<ILogger>& logger): _logger(logger), _container(container)
	{
	}

	template <class TViewModel>
	void GoTo(std::function<void(std::shared_ptr<TViewModel>)> callback, bool pushCurrentToHistory = true)
	{
		_currentView = _container->resolve<ViewBase<TViewModel>>();
	}

	template <class TViewModel>
	void GoTo()
	{
		GoTo<TViewModel>([](std::shared_ptr<TViewModel> vm)
		{
			//
		});
	}

	template <class TViewModel>
	void GoTo(std::shared_ptr<TViewModel> viewModel)
	{
		//
	}

	template <class TViewModel>
	void GoBack(std::function<void(std::shared_ptr<TViewModel>)> callback)
	{
	}

	void GoBack()
	{
	}

	std::shared_ptr<IView> CurrentView() const { return _currentView; }
};
