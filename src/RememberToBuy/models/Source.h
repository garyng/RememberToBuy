#pragma once
#include <string>

class Source
{
private:
	int _id{};
	std::string _name;
	std::string _address;

public:
	Source(const int id, const std::string& name, const std::string& address);
	Source();

	int Id() const;
	void Id(int value);

	std::string Name() const;
	void Name(std::string value);

	std::string Address() const;
	void Address(std::string value);
};
