#pragma once

class ItemSource
{
private:
	int _id{};
	int _itemId{};
	int _sourceId{};
	double _price{};

public:
	ItemSource(const int id, const int itemId, const int sourceId, const double price);
	ItemSource();

	int Id() const;
	void Id(int value);

	int ItemId() const;
	void ItemId(int value);

	int SourceId() const;
	void SourceId(int value);

	double Price() const;
	void Price(double value);
};
