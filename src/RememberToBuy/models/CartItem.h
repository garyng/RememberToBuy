#pragma once

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
