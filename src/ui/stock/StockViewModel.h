#pragma once
#include "ui/ViewModelBase.h"

class StockViewModel : public ViewModelBase
{
public:
	StockViewModel(const std::shared_ptr<NavigationService>& navigationService, const std::shared_ptr<ILogger>& logger,
	               const std::shared_ptr<CommandDispatcher>& commandDispatcher,
	               const std::shared_ptr<QueryDispatcher>& queryDispatcher);

	std::string Name() override;
};
