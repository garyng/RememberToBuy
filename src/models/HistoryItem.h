#pragma once
#include <string>
#include <nlohmann/json.hpp>

class HistoryItem
{
private:
	int _id{};
	int _itemId{};
	int _quantity{};
	int _sourceId{};
	double _price{};
	std::string _date;

public:
	HistoryItem(const int id, const int itemId, const int quantity, const int sourceId, const double price,
	            const std::string& date);

	HistoryItem();

	int Id() const;
	void Id(int value);

	int ItemId() const;
	void ItemId(int value);

	int Quantity() const;
	void Quantity(int value);

	int SourceId() const;
	void SourceId(int value);

	double Price() const;
	void Price(double value);

	std::string Date() const;
	void Date(std::string value);
};

void to_json(nlohmann::json& json, const HistoryItem& historyItem);
void from_json(const nlohmann::json& json, HistoryItem& historyItem);
