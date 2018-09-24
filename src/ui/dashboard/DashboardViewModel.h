#pragma once
#include "ui/ViewModelBase.h"
#include "query/GetAllCartItems.h"
#include "models/CartItem.h"
#include "ui/history/HistoryViewModel.h"
#include "ui/cart/CartViewModel.h"

class DashboardViewModel : public ViewModelBase
{
public:
	DashboardViewModel(const std::shared_ptr<NavigationService>& navigationService,
	                   const std::shared_ptr<ILogger>& logger,
	                   const std::shared_ptr<CommandDispatcher>& commandDispatcher,
	                   const std::shared_ptr<QueryDispatcher>& queryDispatcher);

	std::string Name() override;

	int _cartItemCount;
	int CartItemCount() const;

	void GoToCartCommand();

	void GoToHistoryCommand();
};
