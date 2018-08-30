#include "stdafx.h"
#include "CartViewModel.h"


CartViewModel::CartViewModel(const std::shared_ptr<NavigationService>& navigationService,
                             const std::shared_ptr<ILogger>& logger,
                             const std::shared_ptr<CommandDispatcher>& commandDispatcher,
                             const std::shared_ptr<QueryDispatcher>& queryDispatcher): ViewModelBase(
	navigationService, logger, commandDispatcher, queryDispatcher)
{
}

std::string CartViewModel::Name()
{
	return NAMEOF(CartViewModel);
}
