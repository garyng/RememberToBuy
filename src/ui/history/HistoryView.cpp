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
	ImGui::BeginDefaultCenteredResizableWindow("History");
	RenderGoBackButton();

	if (_viewModel->HistoryItems().empty())
	{
		if (_viewModel->IsSearching())
		{
			ImGui::Columns(2);
			RenderSearchNoResult();
			ImGui::NextColumn();
			ImGui::NoItemSelectedPrompt("NoItemSelected");
		}
		else
		{
			RenderNoItems();
		}
	}
	else
	{
		ImGui::Columns(2);

		RenderMaster();

		ImGui::NextColumn();


		if (_viewModel->SelectedIndex().has_value())
		{
			RenderDetails();
		}
		else
		{
			ImGui::NoItemSelectedPrompt("NoItemSelected");
		}
	}

	ImGui::End();
}

void HistoryView::RenderMaster()
{
	ImGui::BeginChildWithBottomSpace("Master", 2);
	{
		int index = 0;
		for (auto&& historyItem : _viewModel->HistoryItems())
		{
			Item item = historyItem.Item();
			Source source = historyItem.Source();
			std::string name = item.Name() + "##" + std::to_string(index);

			if (ImGui::Selectable(name.c_str(),
			                      _viewModel->SelectedIndex() && (index == _viewModel->SelectedIndex().value())))
			{
				_viewModel->SelectedIndex(index);
			}

			if (ImGui::IsItemHovered())
			{
				ImGui::BeginTooltip();

				std::string date = historyItem.Date();
				int quantity = historyItem.Quantity();
				double price = historyItem.Price();
				double subTotal = quantity * price;


				ImGui::Text(("Bought from " + source.Name()).c_str());
				ImGui::Text(("at " + date).c_str());
				ImGui::Text(("Quantity: " + std::to_string(quantity)).c_str());
				ImGui::Text(formatCurrency(price, "Price").c_str());
				ImGui::Text(formatCurrency(subTotal, "Subtotal").c_str());

				ImGui::EndTooltip();
			}
			index++;
		}
	}
	ImGui::EndChild();

	RenderSortByButtons();
	RenderSearchBox();
}

void HistoryView::RenderDetails()
{
	HistoryItem historyItem = _viewModel->SelectedItem().value();
	Item item = historyItem.Item();
	Category category = item.Category();
	Source source = historyItem.Source();

	ImGui::BeginChild("Details");
	{
		ImGui::TextLightTitle1(item.Name());
		ImGui::TextColored(Colors::Grey500, category.Name().c_str());
		ImGui::Separator();
		ImGui::TextBoldNormal("Bought from:");
		ImGui::TextLightTitle2(source.Name());
		ImGui::TextBoldNormal("Price per unit:");
		ImGui::Text(formatCurrency(historyItem.Price()).c_str());

		ImGui::TextBoldNormal("Quantity:");
		ImGui::Text(std::to_string(historyItem.Quantity()).c_str());
		ImGui::TextBoldNormal("Subtotal:");
		double subTotal = historyItem.Quantity() * historyItem.Price();
		ImGui::TextLightTitle2(formatCurrency(subTotal));
	}
	ImGui::EndChild();
}

void HistoryView::RenderNoItems()
{
	ImGui::BeginChild("NoItems");
	ImGui::BlankScreenPrompt(ICON_FA_ROBOT, {"Nothing here!"});
	ImGui::EndChild();
}

void HistoryView::RenderSearchNoResult()
{
	ImGui::BeginChildWithBottomSpace("NoResult", 2);
	{
		ImGui::BlankScreenPrompt(ICON_FA_SPLOTCH, {"No result..."});
	}
	ImGui::EndChild();
	RenderSortByButtons();
	RenderSearchBox();
}

void HistoryView::RenderSortByButtons()
{
	for (auto field : HistoryItemFields::_values())
	{
		if (ImGui::RadioButton((+field)._to_string(), _viewModel->MasterSortKey() == field))
		{
			_viewModel->MasterSortKey(field);
		}
		ImGui::SameLine();
	}

	bool isAscending = _viewModel->IsAscending();
	ImGui::CheckButton(
		(isAscending ? ICON_FA_LONG_ARROW_ALT_DOWN " Ascending" : ICON_FA_LONG_ARROW_ALT_UP " Descending"),
		&isAscending);
	_viewModel->IsAscending(isAscending);
}

void HistoryView::RenderSearchBox()
{
	char searchStringBuffer[255];
	FillCharBuffer(searchStringBuffer, 255, _viewModel->SearchString());

	if (ImGui::InputText(ICON_FA_SEARCH " Filter by", searchStringBuffer, IM_ARRAYSIZE(searchStringBuffer)))
	{
		_viewModel->SearchString(searchStringBuffer);
	}
}
