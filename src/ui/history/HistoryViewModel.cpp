#include "stdafx.h"
#include "HistoryViewModel.h"

HistoryViewModel::HistoryViewModel(const std::shared_ptr<NavigationService>& navigationService,
                                   const std::shared_ptr<ILogger>& logger): ViewModelBase(navigationService, logger)
{
}

std::string HistoryViewModel::Name()
{
	return NAMEOF(HistoryViewModel);
}
