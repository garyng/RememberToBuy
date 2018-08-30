#pragma once
#include "logger/ILogger.h"

class NullLogger : public ILogger
{
public:
	void Debug(std::string message) override
	{
		
	}
	void Info(std::string message) override
	{
		
	}
	void Warn(std::string message) override
	{
		
	}
	void Error(std::string message) override
	{
		
	}
};
