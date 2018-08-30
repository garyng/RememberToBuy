﻿#pragma once
#include <nlohmann/json.hpp>

class CartItem
{
private:
	int _id{};
	int _itemId{};
	int _quantity{};
	int _sourceId{};

public:
	CartItem(const int id, const int itemId, const int quantity, const int sourceId);
	CartItem();

	int Id() const;
	void Id(int value);

	int ItemId() const;
	void ItemId(int value);

	int Quantity() const;
	void Quantity(int value);

	int SourceId() const;
	void SourceId(int value);
};

void to_json(nlohmann::json& json, const CartItem& item);
void from_json(const nlohmann::json& json, CartItem& item);