#pragma once
#include "ui/ViewModelBase.h"
#include "models/CartItem.h"
#include "query/GetAllCartItems.h"

class CartItemDto
{
	
};

class CartViewModel : public ViewModelBase
{
private:
	std::vector<CartItem> _cartItems;

public:

	CartViewModel(const std::shared_ptr<NavigationService>& navigationService, const std::shared_ptr<ILogger>& logger,
	              const std::shared_ptr<CommandDispatcher>& commandDispatcher,
	              const std::shared_ptr<QueryDispatcher>& queryDispatcher);

	void LoadCartItemsCommand()
	{
		_cartItems = _queryDispatcher->Dispatch<std::vector<CartItem>>(GetAllCartItems{});
		
	}

	std::vector<CartItem> CartItems() const { return _cartItems; }
	void CartItems(std::vector<CartItem> value) { _cartItems = value; }


	std::string Name() override;
};
