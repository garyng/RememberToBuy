#pragma once
#include "JsonStorage.h"
#include "models/CartItem.h"

class CartItemStorage : public JsonStorage<CartItem>
{
public:
	CartItemStorage(const std::shared_ptr<ILogger>& logger);

protected:
	std::string Filename() const override;
	std::vector<CartItem> DefaultData() const override;
};
