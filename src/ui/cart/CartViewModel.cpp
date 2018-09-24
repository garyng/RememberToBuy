#include "stdafx.h"
#include "CartViewModel.h"
#include "ui/utils/Sorter.h"
#include "query/GetAllCartItems.h"
#include "storage/CartItemStorage.h"
#include "command/RemoveCartItem.h"
#include "command/CheckOffCartItem.h"
#include "SelectSourceViewModel.h"
#include "SelectItemViewModel.h"

CartViewModel::CartViewModel(const std::shared_ptr<NavigationService>& navigationService,
                             const std::shared_ptr<ILogger>& logger,
                             const std::shared_ptr<CommandDispatcher>& commandDispatcher,
                             const std::shared_ptr<QueryDispatcher>& queryDispatcher): ViewModelBase(
	navigationService, logger, commandDispatcher, queryDispatcher)
{
}

void CartViewModel::GetCartItemsCommand()
{
	using namespace coveo::linq;

	_cartItems = _queryDispatcher->Dispatch<std::vector<CartItem>>(GetAllCartItems{});
	if (IsSearching())
	{
		_cartItems = _cartItems
			| where([&](const CartItem& cartItem)
			{
				Item item = cartItem.Item();
				Source source = cartItem.Source();
				return boost::icontains(item.Name(), _searchString) ||
					boost::icontains(source.Name(), _searchString);
			})
			| to_vector();
		_selectedIndex = {};
	}
}

void CartViewModel::SortCartItemsCommand()
{
	Sorter::Sort(_cartItems, _cartItemSortKey, _isAscending);
}

void CartViewModel::GoToSelectSourceCommand()
{
	_navigationService->GoTo<SelectSourceViewModel>([&](std::shared_ptr<SelectSourceViewModel> vm)
	{
		vm->SelectedCartItem(SelectedCartItem().value());
	}, false);
}

void CartViewModel::UpdateCartItemQuantityCommand(int cartItemId, int quantity)
{
	_logger->Debug("CartItem #" + std::to_string(cartItemId) + ": New quantity " + std::to_string(quantity));
	UpdateCartItemQuantity command{cartItemId, quantity};
	_commandDispatcher->Dispatch(command);
	GetCartItemsCommand();
}

void CartViewModel::RemoveSelectedCartItemCommand()
{
	RemoveCartItem command = RemoveCartItem{SelectedCartItem()->Id()};
	_commandDispatcher->Dispatch(command);
	GetCartItemsCommand();
}

void CartViewModel::CheckOffSelectedCartItemCommand()
{
	CheckOffCartItem command = CheckOffCartItem{SelectedCartItem()->Id()};
	_commandDispatcher->Dispatch(command);
	GetCartItemsCommand();
}

std::string CartViewModel::Name()
{
	return NAMEOF(CartViewModel);
}

void CartViewModel::GoToSelectItemCommand()
{
	_navigationService->GoTo<SelectItemViewModel>([](auto vm)
	{
	}, false);
}
