#pragma once
#include "ui/ViewModelBase.h"
#include "models/Item.h"
#include "models/CartItem.h"

class SelectItemViewModel : public ViewModelBase,
                            public ICanReset
{
private:
	std::optional<int> _selectedIndex;
	std::string _searchString;
	std::vector<Item> _items;
	bool _isAscending;


public:
	SelectItemViewModel(const std::shared_ptr<NavigationService>& navigationService,
	                    const std::shared_ptr<ILogger>& logger,
	                    const std::shared_ptr<CommandDispatcher>& commandDispatcher,
	                    const std::shared_ptr<QueryDispatcher>& queryDispatcher);

	std::string Name() override
	{
		return NAMEOF(SelectItemViewModel);
	}

	std::string SearchString() const { return _searchString; }

	void SearchString(std::string value)
	{
		_searchString = value;
		GetItemsCommand();
	}

	bool IsSearching() const { return _searchString != ""; }

	std::optional<int> SelectedIndex() const { return _selectedIndex; }
	void SelectedIndex(int value) { _selectedIndex = value; }

	std::vector<Item> Items() const { return _items; }
	void Items(std::vector<Item> value) { _items = value; }

	std::optional<Item> SelectedItem() const
	{
		if (_selectedIndex && (_selectedIndex >= 0 || _selectedIndex < Items().size()))
		{
			return Items().at(_selectedIndex.value());
		}
		return {};
	}

	bool IsAscending() const { return _isAscending; }

	void IsAscending(bool value)
	{
		if (_isAscending == value) return;
		_isAscending = value;
		SortItemsCommand();
	}

	std::optional<ItemSource> SelectedItemBestSource();

	ItemFields _masterSortKey = ItemFields::Name;
	ItemFields MasterSortKey() const { return _masterSortKey; }
	void MasterSortKey(ItemFields value)
	{
		if (_masterSortKey == value) return;
		_masterSortKey = value;
		SortItemsCommand();
	}


	void Reset() override;
	void GetItemsCommand();
	void SortItemsCommand();


	void GoToCart() const;
	void GoBackCommand() const override;

	void AddSelectedItemCommand();
};
