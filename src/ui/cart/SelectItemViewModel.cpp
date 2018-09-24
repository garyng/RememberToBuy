#include "stdafx.h"
#include "SelectItemViewModel.h"
#include "CartViewModel.h"
#include "storage/ItemStorage.h"
#include "proxy/ProxyFactory.h"
#include "query/GetAllItems.h"
#include "ui/utils/Sorter.h"
#include "storage/ItemSourceStorage.h"
#include "query/GetBestSourceByItemId.h"
#include "storage/CartItemStorage.h"
#include "command/AddCartItem.h"

SelectItemViewModel::SelectItemViewModel(const std::shared_ptr<NavigationService>& navigationService,
                                         const std::shared_ptr<ILogger>& logger,
                                         const std::shared_ptr<CommandDispatcher>& commandDispatcher,
                                         const std::shared_ptr<QueryDispatcher>& queryDispatcher): ViewModelBase(
	navigationService, logger, commandDispatcher, queryDispatcher)
{
}

std::optional<ItemSource> SelectItemViewModel::SelectedItemBestSource()
{
	if (SelectedItem())
	{
		Item item = SelectedItem().value();
		return _queryDispatcher->Dispatch<ItemSource>(GetBestSourceByItemId{item.Id()});
	}
	return {};
}

void SelectItemViewModel::Reset()
{
	GetItemsCommand();
	_selectedIndex = {};
	SearchString("");
}

void SelectItemViewModel::GetItemsCommand()
{
	_items = _queryDispatcher->Dispatch<std::vector<Item>>(GetAllItems{});

	if (IsSearching())
	{
		_items = _items
			| where([&](const Item& item)
			{
				Category category = item.Category();
				return boost::icontains(item.Name(), _searchString) || boost::icontains(category.Name(), _searchString);
			})
			| to_vector();
		_selectedIndex = {};
	}
}

void SelectItemViewModel::SortItemsCommand()
{
	Sorter::Sort(_items, _masterSortKey, _isAscending);
}

void SelectItemViewModel::GoBackCommand() const
{
	_navigationService->GoTo<CartViewModel>([](std::shared_ptr<CartViewModel> vm)
	{
	}, false);
}

void SelectItemViewModel::AddSelectedItemCommand()
{
	Item item = SelectedItem().value();
	ItemSource itemSource = SelectedItemBestSource().value();
	AddCartItem command{item.Id(), itemSource.SourceId()};

	_commandDispatcher->Dispatch(command);

	_navigationService->GoTo<CartViewModel>([&](std::shared_ptr<CartViewModel> vm)
	{
		vm->SortCartItemsCommand();
		std::vector<CartItem> cartItems = vm->CartItems();

		auto found = std::find_if(cartItems.begin(), cartItems.end(), [&](const CartItem& cartItem)
		{
			return cartItem.Id() == command.id;
		});
		if (found != cartItems.end())
		{
			vm->SelectedIndex(std::distance(cartItems.begin(), found));
		}
	}, false);
}
