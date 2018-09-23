#pragma once
#include <nlohmann/json.hpp>
#include "proxy/ItemProxy.h"
#include "proxy/SourceProxy.h"
#include "proxy/ItemSourceProxy.h"

BETTER_ENUM(CartItemFields, int, Name /* Item's name */, Quantity);

class CartItem
{
private:
	int _id{};
	int _itemId{};
	int _quantity{};
	int _sourceId{};

	ItemProxy _item{};
	SourceProxy _source{};
	ItemSourceProxy _itemSource;


public:
	CartItem(const int id, const int itemId, const int quantity, const int sourceId);
	CartItem();

	int Id() const;
	void Id(int value);

	int ItemId() const;
	void ItemId(int value);

	ItemProxy Item() const;
	void Item(ItemProxy value);

	int Quantity() const;
	void Quantity(int value);

	int SourceId() const;
	void SourceId(int value);

	SourceProxy Source() const;
	void Source(SourceProxy value);

	ItemSourceProxy ItemSource() const;
	void ItemSource(ItemSourceProxy value);
};

void to_json(nlohmann::json& json, const CartItem& item);
void from_json(const nlohmann::json& json, CartItem& item);
