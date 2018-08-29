#include "stdafx.h"
#include "Source.h"

Source::Source(const int id, const std::string& name, const std::string& address): _id(id),
                                                                                   _name(name),
                                                                                   _address(address)
{
}

Source::Source() = default;

int Source::Id() const
{
	return _id;
}

void Source::Id(int value)
{
	_id = value;
}

std::string Source::Name() const
{
	return _name;
}

void Source::Name(std::string value)
{
	_name = value;
}

std::string Source::Address() const
{
	return _address;
}

void Source::Address(std::string value)
{
	_address = value;
}

void to_json(nlohmann::json& json, const Source& source)
{
	json = nlohmann::json{
		{"Id", source.Id()},
		{"Name", source.Name()},
		{"Address", source.Address()}
	};
}

void from_json(const nlohmann::json& json, Source& source)
{
	source.Id(json.at("Id").get<int>());
	source.Name(json.at("Name").get<std::string>());
	source.Address(json.at("Address").get<std::string>());
}
