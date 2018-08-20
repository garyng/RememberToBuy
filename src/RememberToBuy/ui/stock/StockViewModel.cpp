#include "stdafx.h"
#include "StockViewModel.h"

StockViewModel::StockViewModel(const std::shared_ptr<NavigationService>& navigationService,
                               const std::shared_ptr<ILogger>& logger): ViewModelBase(navigationService, logger)
{
}

std::string StockViewModel::Name()
{
	return NAMEOF(StockViewModel);
}
