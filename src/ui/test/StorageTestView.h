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

		ImGui::Columns(2);

		RenderResetAndEmptyStorageButton();

		RenderResetAndEmptyAllStorageButton();
		ImGui::End();
	}

	void RenderResetAndEmptyStorageButton() const
	{
		for (const auto& storage : _storages)
		{
			std::string name = std::string(typeid(*storage).name());
			std::string restorePopupName = "Are you sure?##Restore" + name;
			std::string restoreText = "Reset " + name;

			if (ImGui::FullWidthButton(restoreText.c_str()))
			{
				ImGui::OpenPopup(restorePopupName.c_str());
			}
			ImGui::NextColumn();

			std::string emptyPopupName = "Are you sure?##Empty" + name;
			std::string emptyText = "Empty " + name;

			if (ImGui::FullWidthButton(emptyText.c_str()))
			{
				ImGui::OpenPopup(emptyPopupName.c_str());
			}

			ImGui::NextColumn();

			ImGui::OkCancelPopupModel(restorePopupName.c_str(), ICON_FA_EXCLAMATION_CIRCLE,
			                          {
				                          "Restoring " + name,
				                          "Are you sure?"
			                          }, [&]()
			                          {
				                          storage->Restore();
			                          }, "Yes", "No");
			ImGui::OkCancelPopupModel(emptyPopupName.c_str(), ICON_FA_EXCLAMATION_CIRCLE,
			                          {
				                          "Emptying " + name,
				                          "Are you sure?"
			                          }, [&]()
			                          {
				                          storage->Clear();
			                          }, "Yes", "No");
		}
	}

	void RenderResetAndEmptyAllStorageButton()
	{
		if (ImGui::FullWidthButton("Reset all storage"))
		{
			ImGui::OpenPopup("Are you sure?##Reset");
		}
		ImGui::NextColumn();

		if (ImGui::FullWidthButton("Empty all storage"))
		{
			ImGui::OpenPopup("Are you sure?##Empty");
		}

		ImGui::OkCancelPopupModel("Are you sure?##Reset", ICON_FA_EXCLAMATION_CIRCLE,
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
		ImGui::OkCancelPopupModel("Are you sure?##Empty", ICON_FA_EXCLAMATION_CIRCLE,
		                          {
			                          "Emptying all storage",
			                          "Are you sure?"
		                          }, [&]()
		                          {
			                          for (const auto& storage : _storages)
			                          {
				                          storage->Clear();
			                          }
		                          }, "Yes", "No");
	}
};
