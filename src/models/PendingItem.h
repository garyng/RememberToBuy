#pragma once
#include <nlohmann/json.hpp>
#include "proxy/ItemProxy.h"

class PendingItem
{
private:
	int _id{};
	int _itemId{};
	int _quantity{};

	ItemProxy _item{};
public:
	PendingItem(const int id, const int itemId, const int quantity);

	PendingItem();

	int Id() const;
	void Id(int value);

	int ItemId() const;
	void ItemId(int value);

	ItemProxy Item() const;
	void Item(ItemProxy value);

	int Quantity() const;
	void Quantity(int value);
};

void to_json(nlohmann::json& json, const PendingItem& pendingItem);
void from_json(const nlohmann::json& json, PendingItem& pendingItem);
