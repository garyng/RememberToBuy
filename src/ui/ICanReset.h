#pragma once
class ICanReset
{
public:
	virtual ~ICanReset() = default;
	virtual void Reset() = 0;
};
