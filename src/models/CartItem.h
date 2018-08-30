#pragma once
#include <nlohmann/json.hpp>
#include "proxy/ItemProxy.h"

class CartItem
{
private:
	int _id{};
	int _itemId{};
	int _quantity{};
	int _sourceId{};

	std::shared_ptr<ItemProxy> _item;

public:
	CartItem(const int id, const int itemId, const int quantity, const int sourceId);
	CartItem();

	int Id() const;
	void Id(int value);

	int ItemId() const;
	void ItemId(int value);

	std::shared_ptr<ItemProxy> Item() const { return _item; }
	void Item(std::shared_ptr<ItemProxy> value) { _item = value; }

	int Quantity() const;
	void Quantity(int value);

	int SourceId() const;
	void SourceId(int value);
};

void to_json(nlohmann::json& json, const CartItem& item);
void from_json(const nlohmann::json& json, CartItem& item);
