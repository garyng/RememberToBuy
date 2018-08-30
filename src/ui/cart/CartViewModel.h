#pragma once
#include "ui/ViewModelBase.h"
#include "models/CartItem.h"
#include "storage/CartItemStorage.h"

class CartViewModel : public ViewModelBase
{
public:

	CartViewModel(const std::shared_ptr<NavigationService>& navigationService, const std::shared_ptr<ILogger>& logger,
	              const std::shared_ptr<CommandDispatcher>& commandDispatcher,
	              const std::shared_ptr<QueryDispatcher>& queryDispatcher);

	std::string Name() override;

	//void LoadCartItemsCommand()
	//{

	//}
	
};
