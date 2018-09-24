#pragma once
#include "ILogger.h"
#include <iostream>

class ConsoleLogger : public ILogger
{
public:

	void Debug(std::string message) override
	{
		std::cout << "[DEBUG] " << message << std::endl;
	}

	void Info(std::string message) override
	{
		std::cout << "[INFO] " << message << std::endl;
	}

	void Warn(std::string message) override
	{
		std::cout << "[WARN] " << message << std::endl;
	}

	void Error(std::string message) override
	{
		std::cout << "[ERROR] " << message << std::endl;
	}
};
