#pragma once
#include "ui/ViewModelBase.h"

class PendingViewModel : public ViewModelBase
{
public:
	PendingViewModel(const std::shared_ptr<NavigationService>& navigationService,
	                 const std::shared_ptr<ILogger>& logger,
	                 const std::shared_ptr<CommandDispatcher>& commandDispatcher,
	                 const std::shared_ptr<QueryDispatcher>& queryDispatcher);

	std::string Name() override;
};
