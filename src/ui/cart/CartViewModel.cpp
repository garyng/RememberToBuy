#include "stdafx.h"
#include "CartViewModel.h"
#include "ui/utils/Sorter.h"
#include "query/GetAllCartItems.h"

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
	}
}

void CartViewModel::SortCartItemsCommand()
{
	Sorter::Sort(_cartItems, _cartItemSortKey, _isAscending);
}

std::string CartViewModel::Name()
{
	return NAMEOF(CartViewModel);
}
