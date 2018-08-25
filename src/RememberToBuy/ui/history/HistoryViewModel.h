#pragma once
#include "ui/ViewModelBase.h"

class HistoryViewModel : public ViewModelBase
{
public:
	HistoryViewModel(const std::shared_ptr<NavigationService>& navigationService,
	                 const std::shared_ptr<ILogger>& logger);

	std::string Name() override;
};
