#pragma once
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

		RenderResetStorageButton();
		RenderResetAllStorageButton();
		ImGui::End();
	}

	void RenderResetStorageButton() const
	{
		for (const auto& storage : _storages)
		{
			std::string name = std::string(typeid(*storage).name());
			std::string popupName = "Are you sure?##" + name;
			std::string text = "Reset " + name;

			if (ImGui::FullWidthButton(text.c_str()))
			{
				ImGui::OpenPopup(popupName.c_str());
			}

			ImGui::OkCancelPopupModel(popupName.c_str(), ICON_FA_EXCLAMATION_CIRCLE,
			                          {
				                          "Restoring " + name,
				                          "Are you sure?"
			                          }, [&]()
			                          {
				                          storage->Restore();
			                          }, "Yes", "No");
		}
	}

	void RenderResetAllStorageButton()
	{
		if (ImGui::FullWidthButton("Reset all storage"))
		{
			ImGui::OpenPopup("Are you sure?");
		}

		ImGui::OkCancelPopupModel("Are you sure?", ICON_FA_EXCLAMATION_CIRCLE,
		                          {
			                          "Restoring all storage",
			                          "Are you sure?"
		                          }, [&]()
		                          {
			                          for (const auto& storage : _storages)
			                          {
				                          storage->Restore();
			                          }
		                          }, "Yes", "No");
	}
};
