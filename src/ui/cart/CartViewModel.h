#pragma once
#include <optional>
#include "ui/ViewModelBase.h"
#include "models/CartItem.h"
#include "command/UpdateCartItemQuantity.h"

class CartViewModel : public ViewModelBase,
                      public ICanReset
{
private:
	std::vector<CartItem> _cartItems;
	std::optional<int> _selectedIndex;
	std::string _searchString;
	CartItemFields _cartItemSortKey = CartItemFields::Name;
	bool _isAscending;

public:

	CartViewModel(const std::shared_ptr<NavigationService>& navigationService, const std::shared_ptr<ILogger>& logger,
	              const std::shared_ptr<CommandDispatcher>& commandDispatcher,
	              const std::shared_ptr<QueryDispatcher>& queryDispatcher);

	void GetCartItemsCommand();

	void SortCartItemsCommand();

	CartItemFields CartItemSortKey() const { return _cartItemSortKey; }

	void CartItemSortKey(CartItemFields value)
	{
		if (_cartItemSortKey == value) return;
		_cartItemSortKey = value;

		SortCartItemsCommand();
	}

	bool IsAscending() const { return _isAscending; }

	void IsAscending(bool value)
	{
		if (_isAscending == value) return;
		_isAscending = value;
		SortCartItemsCommand();
	}


	std::vector<CartItem> CartItems() const { return _cartItems; }
	void CartItems(std::vector<CartItem> value) { _cartItems = value; }

	std::optional<int> SelectedIndex() const { return _selectedIndex; }
	void SelectedIndex(int value) { _selectedIndex = value; }

	std::optional<CartItem> SelectedCartItem() const
	{
		if (_selectedIndex && (_selectedIndex >= 0 || _selectedIndex < _cartItems.size()))
		{
			return _cartItems.at(_selectedIndex.value());
		}
		return {};
	}

	void GoToSelectSourceCommand();

	std::string SearchString() const { return _searchString; }

	void SearchString(std::string value)
	{
		_searchString = value;
		GetCartItemsCommand();
	}

	bool IsSearching() const { return _searchString != ""; }

	void UpdateCartItemQuantityCommand(int cartItemId, int quantity);

	void RemoveSelectedCartItemCommand();

	void CheckOffSelectedCartItemCommand();

	std::string Name() override;

	void Reset() override
	{
		GetCartItemsCommand();
		_selectedIndex = {};
		SearchString("");
	}

	void GoToSelectItemCommand();
};
