#include "stdafx.h"
#include "PendingViewModel.h"

PendingViewModel::PendingViewModel(const std::shared_ptr<NavigationService>& navigationService,
                                   const std::shared_ptr<ILogger>& logger): ViewModelBase(navigationService, logger)
{
}

std::string PendingViewModel::Name()
{
	return NAMEOF(PendingViewModel);
}
