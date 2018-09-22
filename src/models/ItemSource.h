#pragma once
#include <nlohmann/json.hpp>
#include "proxy/ItemProxy.h"
#include "proxy/SourceProxy.h"

class ItemSource
{
private:
	int _id{};
	int _itemId{};
	int _sourceId{};
	double _price{};

	ItemProxy _item{};
	SourceProxy _source{};

public:
	ItemSource(const int id, const int itemId, const int sourceId, const double price);
	ItemSource();

	int Id() const;
	void Id(int value);

	int ItemId() const;
	void ItemId(int value);

	ItemProxy Item() const;
	void Item(ItemProxy value);

	int SourceId() const;
	void SourceId(int value);

	SourceProxy Source() const;
	void Source(SourceProxy value);


	double Price() const;
	void Price(double value);
};

void to_json(nlohmann::json& json, const ItemSource& itemSource);
void from_json(const nlohmann::json& json, ItemSource& itemSource);
