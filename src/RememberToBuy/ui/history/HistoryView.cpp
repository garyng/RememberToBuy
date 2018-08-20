#include "stdafx.h"
#include "HistoryView.h"

HistoryView::
HistoryView(const std::shared_ptr<HistoryViewModel>& viewModel,
            const std::shared_ptr<ILogger>& logger): ViewBase<HistoryViewModel>(viewModel, logger)
{
}

std::string HistoryView::Name() const
{
	return NAMEOF(HistoryView);
}

void HistoryView::Render()
{
}
