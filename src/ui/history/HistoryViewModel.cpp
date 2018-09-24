#include "stdafx.h"
#include "HistoryViewModel.h"
#include "ui/utils/Sorter.h"


HistoryViewModel::HistoryViewModel(const std::shared_ptr<NavigationService>& navigationService,
                                   const std::shared_ptr<ILogger>& logger,
                                   const std::shared_ptr<CommandDispatcher>& commandDispatcher,
                                   const std::shared_ptr<QueryDispatcher>& queryDispatcher): ViewModelBase(
	navigationService, logger, commandDispatcher, queryDispatcher)
{
}

std::string HistoryViewModel::Name()
{
	return NAMEOF(HistoryViewModel);
}

void HistoryViewModel::GetHistoryItemsCommand()
{
	_historyItems = _queryDispatcher->Dispatch<std::vector<HistoryItem>>(
		GetAllHistoryItems{});
	if (IsSearching())
	{
		_historyItems = _historyItems
			| where([&](const HistoryItem& historyItem)
			{
				Item item = historyItem.Item();
				Source source = historyItem.Source();
				return boost::icontains(item.Name(), _searchString) ||
					boost::icontains(source.Name(), _searchString) ||
					boost::icontains(historyItem.Date(), _searchString);
			})
			| to_vector();
		_selectedIndex = {};
	}
}

void HistoryViewModel::SortItemsCommand()
{
	Sorter::Sort(_historyItems, _masterSortKey, _isAscending);
}
