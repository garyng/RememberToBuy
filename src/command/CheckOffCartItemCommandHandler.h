#pragma once
#include "storage/CartItemStorage.h"
#include "storage/HistoryItemStorage.h"
#include "proxy/ProxyFactory.h"

class CheckOffCartItem;

class CheckOffCartItemCommandHandler : public ICommandHandler<CheckOffCartItem>
{
private:
	std::shared_ptr<CartItemStorage> _cartItemStorage;
	std::shared_ptr<HistoryItemStorage> _historyItemStorage;
	std::shared_ptr<ProxyFactory> _proxyFactory;
public:


	CheckOffCartItemCommandHandler(const std::shared_ptr<CartItemStorage>& cartItemStorage,
		const std::shared_ptr<HistoryItemStorage>& historyItemStorage,
		const std::shared_ptr<ProxyFactory>& proxyFactory)
		: _cartItemStorage(cartItemStorage),
		  _historyItemStorage(historyItemStorage),
		  _proxyFactory(proxyFactory)
	{
	}

	void Handle(CheckOffCartItem& parameter) override;
};
