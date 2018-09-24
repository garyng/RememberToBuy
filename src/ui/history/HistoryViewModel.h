#pragma once
#include "ui/ViewModelBase.h"
#include "models/HistoryItem.h"

class HistoryViewModel : public ViewModelBase,
                         public ICanReset
{
private:
	std::vector<HistoryItem> _historyItems;
	std::string _searchString;
	std::optional<int> _selectedIndex;
	HistoryItemFields _masterSortKey = HistoryItemFields::Name;
	bool _isAscending;

public:


	HistoryViewModel(const std::shared_ptr<NavigationService>& navigationService,
	                 const std::shared_ptr<ILogger>& logger,
	                 const std::shared_ptr<CommandDispatcher>& commandDispatcher,
	                 const std::shared_ptr<QueryDispatcher>& queryDispatcher);

	std::string Name() override;

	std::string SearchString() const { return _searchString; }

	std::vector<HistoryItem> HistoryItems() const { return _historyItems; }
	void HistoryItems(std::vector<HistoryItem> value) { _historyItems = value; }

	void SearchString(std::string value)
	{
		_searchString = value;
		GetHistoryItemsCommand();
	}

	bool IsSearching() const { return _searchString != ""; }

	void GetHistoryItemsCommand();

	std::optional<int> SelectedIndex() const { return _selectedIndex; }
	void SelectedIndex(int value) { _selectedIndex = value; }

	std::optional<HistoryItem> SelectedItem() const
	{
		if (_selectedIndex && (_selectedIndex >= 0 || _selectedIndex < _historyItems.size()))
		{
			return _historyItems.at(_selectedIndex.value());
		}
		return {};
	}

	void Reset() override
	{
		GetHistoryItemsCommand();
		_selectedIndex = {};
		SearchString("");
	}

	HistoryItemFields MasterSortKey() const { return _masterSortKey; }
	void SortItemsCommand();

	void MasterSortKey(HistoryItemFields value)
	{
		if (_masterSortKey == value) return;
		_masterSortKey = value;
		SortItemsCommand();
	}

	bool IsAscending() const { return _isAscending; }

	void IsAscending(bool value)
	{
		if (_isAscending == value) return;
		_isAscending = value;
		SortItemsCommand();
	}
};
