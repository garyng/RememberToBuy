#include "stdafx.h"
#include "UpdateSourceOfAllCartItemsCommandHandler.h"

UpdateSourceOfAllCartItemsCommandHandler::UpdateSourceOfAllCartItemsCommandHandler(
	const std::shared_ptr<CartItemStorage>& cartItemStorage,
	const std::shared_ptr<ItemSourceStorage>& itemSourceStorage, const std::shared_ptr<ProxyFactory>& proxyFactory,
	const std::shared_ptr<ILogger>& logger): _cartItemStorage(cartItemStorage),
	                                         _itemSourceStorage(itemSourceStorage),
	                                         _proxyFactory(proxyFactory),
	                                         _logger(logger)
{
}

void UpdateSourceOfAllCartItemsCommandHandler::Handle(UpdateSourceOfAllCartItems& parameter)
{
	std::vector<CartItem>& cartItems = _cartItemStorage->Data();
	for (auto& cartItem : cartItems)
	{
		bool hasThisInSource = (_itemSourceStorage->Data()
			| where([&](ItemSource itemSource)
			{
				return itemSource.ItemId() == cartItem.ItemId() && itemSource.SourceId() == parameter.sourceId;
			})
			| to_vector()).size() > 0;
		if (hasThisInSource)
		{
			cartItem.SourceId(parameter.sourceId);
			_logger->Debug("Changed source of " + std::to_string(cartItem.Id()));
		}
	}
	_proxyFactory->Apply(cartItems);
	_cartItemStorage->Save();
}
