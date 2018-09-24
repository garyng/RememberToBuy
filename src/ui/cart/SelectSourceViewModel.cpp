#include "stdafx.h"
#include "SelectSourceViewModel.h"
#include "models/ItemSource.h"
#include "storage/ItemSourceStorage.h"
#include "proxy/ProxyFactory.h"
#include "query/GetAllItemSourcesByItemId.h"
#include "CartViewModel.h"
#include "ui/utils/Sorter.h"
#include "command/UpdateSourceByCartItemId.h"
#include "command/UpdateSourceOfAllCartItems.h"

SelectSourceViewModel::SelectSourceViewModel(const std::shared_ptr<NavigationService>& navigationService,
                                             const std::shared_ptr<ILogger>& logger,
                                             const std::shared_ptr<CommandDispatcher>& commandDispatcher,
                                             const std::shared_ptr<QueryDispatcher>& queryDispatcher): ViewModelBase(
	navigationService, logger, commandDispatcher, queryDispatcher)
{
}

void SelectSourceViewModel::GetSourcesCommand()
{
	if (_selectedCartItem)
	{
		_itemSources = _queryDispatcher->Dispatch<std::vector<ItemSource>>(
			GetAllItemSourcesByItemId{_selectedCartItem.value().ItemId()});

		if (IsSearching())
		{
			_itemSources = _itemSources
				| where([&](const ItemSource& itemSource)
				{
					Source source = itemSource.Source();
					return boost::icontains(source.Name(), _searchString);
				})
				| to_vector();
			_selectedIndex = {};
		}
	}
	else
	{
		_itemSources.clear();
	}
}

std::string SelectSourceViewModel::Name()
{
	return NAMEOF(SelectSourceViewModel);
}

void SelectSourceViewModel::SortItemsCommand()
{
	Sorter::Sort(_itemSources, _masterSortKey, _isAscending);
}

void SelectSourceViewModel::Reset()
{
	GetSourcesCommand();
	_selectedIndex = {};
	SearchString("");
}

void SelectSourceViewModel::GoToCart() const
{
	_navigationService->GoTo<CartViewModel>([&](std::shared_ptr<CartViewModel> vm)
	{
		if (SelectedCartItem())
		{
			CartItem selectedCartItem = SelectedCartItem().value();
			std::vector<CartItem> cartItems = vm->CartItems();

			auto found = std::find_if(cartItems.begin(), cartItems.end(), [&](const CartItem& cartItem)
			{
				return cartItem.Id() == selectedCartItem.Id();
			});
			if (found != cartItems.end())
			{
				vm->SelectedIndex(std::distance(cartItems.begin(), found));
			}
		}
	}, false);
}

void SelectSourceViewModel::GoBackCommand() const
{
	// go "back" with go to without pushing current to history
	GoToCart();
}

void SelectSourceViewModel::ApplySelectedSourceCommand()
{
	bool applyAll = _isApplyToAllCartItems;
	CartItem cartItem = SelectedCartItem().value();
	ItemSource itemSource = SelectedItem().value();
	if (applyAll)
	{
		UpdateSourceOfAllCartItems command{itemSource.SourceId()};
		_commandDispatcher->Dispatch(command);
	}
	else
	{
		UpdateSourceByCartItemId command{cartItem.Id(), itemSource.SourceId()};
		_commandDispatcher->Dispatch(command);
	}
	GoToCart();
}
