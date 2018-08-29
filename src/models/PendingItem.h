#pragma once

class PendingItem
{
private:
	int _id{};
	int _itemId{};
	int _quantity{};

public:
	PendingItem(const int id, const int itemId, const int quantity);

	PendingItem();

	int Id() const;
	void Id(int value);

	int ItemId() const;
	void ItemId(int value);

	int Quantity() const;
	void Quantity(int value);
};
