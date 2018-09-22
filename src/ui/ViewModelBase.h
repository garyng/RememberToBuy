#pragma once
#include "IViewModel.h"
#include "navigation/NavigationService.h"

class ViewModelBase : public IViewModel
{
protected:
	std::shared_ptr<NavigationService> _navigationService;
	std::shared_ptr<ILogger> _logger;
	std::shared_ptr<CommandDispatcher> _commandDispatcher;
	std::shared_ptr<QueryDispatcher> _queryDispatcher;
	bool _isSortAscending;

public:
	ViewModelBase(const std::shared_ptr<NavigationService>& navigationService, const std::shared_ptr<ILogger>& logger,
	              const std::shared_ptr<CommandDispatcher>& commandDispatcher,
	              const std::shared_ptr<QueryDispatcher>& queryDispatcher)
		: _navigationService(navigationService),
		  _logger(logger),
		  _commandDispatcher(commandDispatcher),
		  _queryDispatcher(queryDispatcher)
	{
	}

	virtual void GoBackCommand() const
	{
		_navigationService->GoBack();
	}

	virtual bool CanGoBack() const
	{
		return _navigationService->CanGoBack();
	}
};
