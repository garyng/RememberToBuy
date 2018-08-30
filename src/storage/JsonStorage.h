#pragma once
#include <filesystem>
#include <string>
#include "IStorage.h"
#include <fstream>
#include "nlohmann/json.hpp"

template <class TData>
class JsonStorage : public IStorage
{
private:
	std::filesystem::path ResolvePath() const
	{
		const std::filesystem::path dataDirectory{"data"};
		if (!exists(dataDirectory))
		{
			create_directory(dataDirectory);
		}
		return dataDirectory / Filename();
	}

protected:
	std::shared_ptr<ILogger> _logger;
	std::vector<TData> _data;

	virtual std::string Filename() const = 0;
	virtual std::vector<TData> DefaultData() const = 0;

public:
	std::vector<TData>& Data() { return _data; }

	JsonStorage(const std::shared_ptr<ILogger>& logger): _logger(logger)
	{
	}

	~JsonStorage() = default;

	void Load() override
	{
		std::filesystem::path dataFilepath = ResolvePath();
		if (!exists(dataFilepath))
		{
			_logger->Warn("\"" + Filename() + "\" not found! Loading default data.");
			_data = DefaultData();
			return;
		}

		std::ifstream reader{dataFilepath};
		if (!reader.is_open())
		{
			_logger->Warn("Unable to open \"" + Filename() + "\"");
			return;
		}

		nlohmann::json json;
		reader >> json;
		reader.close();

		_data = json.get<std::vector<TData>>();
		_logger->Debug("Loaded data from \"" + Filename() + "\" (" + std::to_string(_data.size()) + " entries)");
	}

	void Save() override
	{
		std::filesystem::path dataFilepath = ResolvePath();
		nlohmann::json json = _data;

		std::ofstream writer{dataFilepath};
		if (!writer.is_open())
		{
			_logger->Warn("Unable to open \"" + Filename() + "\"");
			return;
		}

		writer << json;
		writer.close();
		_logger->Debug("Saved data to \"" + Filename() + "\" (" + std::to_string(_data.size()) + " entries)");
	}

	void Restore() override
	{
		_data = DefaultData();
		_logger->Debug("Restored data to default value");
		Save();
	}
};
