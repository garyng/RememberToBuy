#pragma once
#include "models/CartItem.h"
#include "storage/CartItemStorage.h"
#include "proxy/ProxyFactory.h"
#include "UpdateSourceOfAllCartItems.h"
#include "storage/ItemSourceStorage.h"

class UpdateSourceOfAllCartItemsCommandHandler : public ICommandHandler<UpdateSourceOfAllCartItems>
{
private:
	std::shared_ptr<CartItemStorage> _cartItemStorage;
	std::shared_ptr<ItemSourceStorage> _itemSourceStorage;
	std::shared_ptr<ProxyFactory> _proxyFactory;
	std::shared_ptr<ILogger> _logger;
public:


	UpdateSourceOfAllCartItemsCommandHandler(const std::shared_ptr<CartItemStorage>& cartItemStorage,
	                                         const std::shared_ptr<ItemSourceStorage>& itemSourceStorage,
	                                         const std::shared_ptr<ProxyFactory>& proxyFactory,
	                                         const std::shared_ptr<ILogger>& logger);

	void Handle(UpdateSourceOfAllCartItems& parameter) override;
};
