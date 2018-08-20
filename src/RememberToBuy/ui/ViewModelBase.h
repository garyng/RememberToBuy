#pragma once
#include "IViewModel.h"
#include "navigation/NavigationService.h"

class ViewModelBase : public IViewModel
{
protected:
	const std::shared_ptr<NavigationService>& _navigationService;
	const std::shared_ptr<ILogger>& _logger;
public:
	ViewModelBase(const std::shared_ptr<NavigationService>& navigationService,
	              const std::shared_ptr<ILogger>& logger): _navigationService(navigationService), _logger(logger)
	{
	}

	virtual void GoBackCommand() const
	{
		_navigationService->GoBack();
	}
};
