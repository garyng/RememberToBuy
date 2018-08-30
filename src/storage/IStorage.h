#pragma once
class IStorage
{
public:
	virtual ~IStorage() = default;
	virtual void Load() = 0;
	virtual void Save() = 0;
	virtual void Restore() = 0;

};