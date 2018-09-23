#include "stdafx.h"
#include "SelectStoreDialogView.h"

SelectStoreDialogView::SelectStoreDialogView(const std::shared_ptr<SelectStoreDialogViewModel>& viewModel,
                                             const std::shared_ptr<ILogger>& logger): ViewBase<
	SelectStoreDialogViewModel>(viewModel, logger)
{
}

std::string SelectStoreDialogView::Name() const
{
	return NAMEOF(SelectStoreDialogView);
}

void SelectStoreDialogView::Render()
{
	ImGui::OpenPopup("DialogTest");
	if (ImGui::BeginPopupModal("DialogTest", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		ImGui::Text("");
		ImGui::TextLightTitle1("Testing");

		if (ImGui::FullWidthButton("Close"))
		{
			_viewModel->OnClosedCommand();
		}
		ImGui::EndPopup();
	}
}
