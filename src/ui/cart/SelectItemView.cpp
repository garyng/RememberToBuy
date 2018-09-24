#include "stdafx.h"
#include "SelectItemView.h"

SelectItemView::SelectItemView(const std::shared_ptr<SelectItemViewModel>& viewModel,
                               const std::shared_ptr<ILogger>& logger): ViewBase<SelectItemViewModel>(viewModel, logger)
{
}

void SelectItemView::Render()
{
	ImGui::BeginDefaultCenteredResizableWindow("Select an item");
	RenderGoBackButton();

	if (_viewModel->Items().empty())
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

		if (_viewModel->SelectedIndex())
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

void SelectItemView::RenderSearchNoResult()
{
	ImGui::BeginChildWithBottomSpace("NoResult", 2);
	{
		ImGui::BlankScreenPrompt(ICON_FA_SPLOTCH, {"No result..."});
	}
	ImGui::EndChild();
	RenderSortByButtons();
	RenderSearchBox();
}

void SelectItemView::RenderNoItems()
{
	ImGui::BeginChild("NoItems");
	ImGui::BlankScreenPrompt(ICON_FA_ROBOT, {"Nothing here!"});
	ImGui::EndChild();
}

void SelectItemView::RenderMaster()
{
	ImGui::BeginChildWithBottomSpace("ItemList", 2);
	{
		int index = 0;
		for (auto&& item : _viewModel->Items())
		{
			std::string name = item.Name() + "##" + std::to_string(index);

			if (ImGui::Selectable(name.c_str(),
			                      _viewModel->SelectedIndex() && (index == _viewModel->SelectedIndex().value())))
			{
				_viewModel->SelectedIndex(index);
			}
			index++;
		}
	}
	ImGui::EndChild();
	RenderSortByButtons();
	RenderSearchBox();
}

void SelectItemView::RenderDetails()
{
	Item item = _viewModel->SelectedItem().value();
	Category category = item.Category();
	ItemSource itemSource = _viewModel->SelectedItemBestSource().value();
	Source source = itemSource.Source();
	ImGui::BeginChildWithBottomSpace("Details", 1);
	{
		ImGui::TextLightTitle1(item.Name());
		ImGui::TextColored(Colors::Grey500, category.Name().c_str());

		ImGui::Separator();

		ImGui::TextBoldNormal("Lowest price:");
		ImGui::TextLightTitle1(formatCurrency(itemSource.Price()));

		ImGui::TextBoldNormal("Sold at:");
		ImGui::TextLightTitle1(source.Name());
	}
	ImGui::EndChild();

	RenderSelectButton();
}

void SelectItemView::RenderSortByButtons()
{
	for (auto field : ItemFields::_values())
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

void SelectItemView::RenderSearchBox()
{
	char searchStringBuffer[255];
	FillCharBuffer(searchStringBuffer, 255, _viewModel->SearchString());

	if (ImGui::InputText(ICON_FA_SEARCH " Filter by", searchStringBuffer, IM_ARRAYSIZE(searchStringBuffer)))
	{
		_viewModel->SearchString(searchStringBuffer);
	}
}

void SelectItemView::RenderSelectButton()
{
	if (ImGui::FullWidthButton(ICON_FA_PLUS " Add to cart"))
	{
		ImGui::OpenPopup("Are you sure?##AddItem");
	}

	Item item = _viewModel->SelectedItem().value();
	ItemSource itemSource = _viewModel->SelectedItemBestSource().value();
	Source source = itemSource.Source();

	ImGui::OkCancelPopupModel("Are you sure?##AddItem", ICON_FA_QUESTION_CIRCLE, {
		                          "Add " + item.Name() + " to cart?",
		                          "(will set source to " + source.Name(),
		                          "as it has the lowest price)"
	                          }, [&]()
	                          {
		                          _viewModel->AddSelectedItemCommand();
	                          }, "Yes", "No");
}
