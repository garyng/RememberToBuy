#pragma once
#include "ui/ViewModelBase.h"
#include "models/ItemSource.h"
#include "models/CartItem.h"

class SelectSourceViewModel : public ViewModelBase,
                              public ICanReset
{
private:
	std::string _searchString;
	std::optional<int> _selectedIndex;
	std::vector<ItemSource> _itemSources;
	std::optional<CartItem> _cartItem{};
	bool _isApplyToAllCartItems{false};
	bool _isAscending;
	ItemSourceFields _masterSortKey = ItemSourceFields::Name;


public:
	SelectSourceViewModel(const std::shared_ptr<NavigationService>& navigationService,
	                      const std::shared_ptr<ILogger>& logger,
	                      const std::shared_ptr<CommandDispatcher>& commandDispatcher,
	                      const std::shared_ptr<QueryDispatcher>& queryDispatcher);

	std::optional<CartItem> SelectedCartItem() const { return _cartItem; }

	void SelectedCartItem(CartItem value)
	{
		_cartItem = value;
		GetSourcesCommand();
	}

	std::vector<ItemSource> ItemSources() const { return _itemSources; }
	void ItemSources(std::vector<ItemSource> value) { _itemSources = value; }

	void GetSourcesCommand();

	std::string Name() override;

	std::string SearchString() const { return _searchString; }

	void SearchString(std::string value)
	{
		_searchString = value;
		GetSourcesCommand();
	}

	bool IsSearching() const { return _searchString != ""; }

	std::optional<int> SelectedIndex() const { return _selectedIndex; }
	void SelectedIndex(int value) { _selectedIndex = value; }

	std::optional<ItemSource> SelectedItem() const
	{
		if (_selectedIndex && (_selectedIndex >= 0 || _selectedIndex < ItemSources().size()))
		{
			return ItemSources().at(_selectedIndex.value());
		}
		return {};
	}

	bool IsApplyToAllCartItems() const { return _isApplyToAllCartItems; }
	void IsApplyToAllCartItems(bool value) { _isApplyToAllCartItems = value; }

	ItemSourceFields MasterSortKey() const { return _masterSortKey; }

	void MasterSortKey(ItemSourceFields value)
	{
		if (_masterSortKey == value) return;
		_masterSortKey = value;
		SortItemsCommand();
	}

	void SortItemsCommand();

	bool IsAscending() const { return _isAscending; }

	void IsAscending(bool value)
	{
		if (_isAscending == value) return;
		_isAscending = value;
		SortItemsCommand();
	}

	void Reset() override;
	void GoToCart() const;
	void GoBackCommand() const override;
	void ApplySelectedSourceCommand();
};
