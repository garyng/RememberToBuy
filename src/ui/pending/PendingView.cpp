#include "stdafx.h"
#include "PendingView.h"

PendingView::
PendingView(const std::shared_ptr<PendingViewModel>& viewModel,
            const std::shared_ptr<ILogger>& logger): ViewBase<PendingViewModel>(viewModel, logger)
{
}

std::string PendingView::Name() const
{
	return NAMEOF(PendingView);
}

void PendingView::Render()
{
	ImGui::BeginDefaultCenteredResizableWindow("Pending");
	RenderGoBackButton();

	ImGui::End();
}
