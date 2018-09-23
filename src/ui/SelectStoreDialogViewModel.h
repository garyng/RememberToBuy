#pragma once
#include "ViewModelBase.h"

class SelectStoreDialogViewModel : public ViewModelBase
{
public:
	SelectStoreDialogViewModel(const std::shared_ptr<NavigationService>& navigationService,
	                           const std::shared_ptr<ILogger>& logger,
	                           const std::shared_ptr<CommandDispatcher>& commandDispatcher,
	                           const std::shared_ptr<QueryDispatcher>& queryDispatcher)
		: ViewModelBase(navigationService, logger, commandDispatcher, queryDispatcher)
	{
	}

	std::string Name() override
	{
		return NAMEOF(SelectStoreDialogViewModel);
	}
};
