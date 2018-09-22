#include "stdafx.h"
#include "PendingViewModel.h"

PendingViewModel::PendingViewModel(const std::shared_ptr<NavigationService>& navigationService,
                                   const std::shared_ptr<ILogger>& logger,
                                   const std::shared_ptr<CommandDispatcher>& commandDispatcher,
                                   const std::shared_ptr<QueryDispatcher>& queryDispatcher): ViewModelBase(
	navigationService, logger, commandDispatcher, queryDispatcher)
{
}

std::string PendingViewModel::Name()
{
	return NAMEOF(PendingViewModel);
}
