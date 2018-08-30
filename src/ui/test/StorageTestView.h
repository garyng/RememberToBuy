#pragma once
#include <filesystem>
#include <string>
#include "Utilities.h"
#include "ui/ITestView.h"

class StorageTestView : public ITestView
{
private:
	std::shared_ptr<ILogger> _logger;
	std::vector<std::shared_ptr<IStorage>> _storages;

public:
	StorageTestView(const std::vector<std::shared_ptr<IStorage>>& storages,
	                const std::shared_ptr<ILogger>& logger): _logger(logger), _storages(storages)
	{
	}

	std::string Name() const override
	{
		return NAMEOF(StorageTestView);
	}

	void Render() override
	{
		ImGui::Begin("Test: Storage");

		// todo: confirmation dialog

		RenderResetStorageButton();
		RenderResetAllStorageButton();
		ImGui::End();
	}

	void RenderResetStorageButton() const
	{
		for (const auto& storage : _storages)
		{
			std::string text = "Reset " + std::string(typeid(*storage).name());
			if (ImGui::FullWidthButton(text.c_str()))
			{
				storage->Restore();
			}
		}
	}

	void RenderResetAllStorageButton()
	{
		if (ImGui::FullWidthButton("Reset all storage"))
		{
			for (const auto& storage : _storages)
			{
				storage->Restore();
			}
		}
	}
};
