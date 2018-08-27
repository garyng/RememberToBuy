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
