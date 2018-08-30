#pragma once
#include "ui/ViewModelBase.h"

class StockViewModel : public ViewModelBase
{
public:
	StockViewModel(const std::shared_ptr<NavigationService>& navigationService, const std::shared_ptr<ILogger>& logger);
	std::string Name() override;
};
