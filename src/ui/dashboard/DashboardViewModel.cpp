#include "stdafx.h"
#include "DashboardViewModel.h"

DashboardViewModel::DashboardViewModel(const std::shared_ptr<NavigationService>& navigationService,
                                       const std::shared_ptr<ILogger>& logger,
                                       const std::shared_ptr<CommandDispatcher>& commandDispatcher,
                                       const std::shared_ptr<QueryDispatcher>& queryDispatcher): ViewModelBase(
	navigationService, logger, commandDispatcher, queryDispatcher)
{
}

std::string DashboardViewModel::Name()
{
	return NAMEOF(DashboardViewModel);
}

int DashboardViewModel::CartItemCount() const
{
	return _queryDispatcher->Dispatch<std::vector<CartItem>>(GetAllCartItems{}).size();
}

void DashboardViewModel::GoToCartCommand()
{
	_navigationService->GoTo<CartViewModel>();
}

void DashboardViewModel::GoToHistoryCommand()
{
	_navigationService->GoTo<HistoryViewModel>();
}
