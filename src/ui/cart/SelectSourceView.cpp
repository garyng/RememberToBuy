#include "stdafx.h"
#include "SelectSourceView.h"

SelectSourceView::SelectSourceView(const std::shared_ptr<SelectSourceViewModel>& viewModel,
                                   const std::shared_ptr<ILogger>& logger): ViewBase<SelectSourceViewModel>(
	viewModel, logger)
{
}

std::string SelectSourceView::Name() const
{
	return NAMEOF(SelectSourceView);
}

void SelectSourceView::RenderHeader()
{
	if (_viewModel->SelectedCartItem())
	{
		CartItem cartItem = _viewModel->SelectedCartItem().value();
		Item item = cartItem.Item();
		ImGui::Separator();
		ImGui::TextLightTitle1(item.Name().c_str());
		ImGui::Separator();
	}
}

void SelectSourceView::Render()
{
	ImGui::BeginDefaultCenteredResizableWindow("Select source");
	RenderGoBackButton();

	RenderHeader();

	if (_viewModel->ItemSources().empty())
	{
		if (_viewModel->IsSearching())
		{
			// search no result
			ImGui::Columns(2);

			RenderSearchNoResult();

			ImGui::NextColumn();
			ImGui::NoItemSelectedPrompt("NoItemSelected");
		}
		else
		{
			// no sources?
			RenderNoItems();
		}
	}
	else
	{
		// master

		ImGui::Columns(2);

		RenderMaster();

		// details
		ImGui::NextColumn();


		if (_viewModel->SelectedIndex())
		{
			// has selected
			RenderDetails();
		}
		else
		{
			// no selected
			ImGui::NoItemSelectedPrompt("NoItemSelected");
		}
	}

	ImGui::End();
}

void SelectSourceView::RenderSearchNoResult()
{
	ImGui::BeginChildWithBottomSpace("NoResult", 2);
	{
		ImGui::BlankScreenPrompt(ICON_FA_SPLOTCH, {"No result..."});
	}
	ImGui::EndChild();
	RenderSortByButtons();
	RenderSearchBox();
}

void SelectSourceView::RenderNoItems()
{
	ImGui::BeginChild("NoItems");
	ImGui::BlankScreenPrompt(ICON_FA_ROBOT, {"Nothing here!"});
	ImGui::EndChild();
}

void SelectSourceView::RenderSortByButtons()
{
	for (auto field : ItemSourceFields::_values())
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

void SelectSourceView::RenderSearchBox()
{
	char searchStringBuffer[255];
	FillCharBuffer(searchStringBuffer, 255, _viewModel->SearchString());

	if (ImGui::InputText(ICON_FA_SEARCH " Filter by", searchStringBuffer, IM_ARRAYSIZE(searchStringBuffer)))
	{
		_viewModel->SearchString(searchStringBuffer);
	}
}

void SelectSourceView::RenderApplyButton()
{
	std::string sourceName = _viewModel->SelectedItem().value().Source().Value().Name();
	std::string itemName = _viewModel->SelectedCartItem().value().Item().Value().Name();

	bool isApplyAll = _viewModel->IsApplyToAllCartItems();
	bool clicked = ImGui::FullWidthButton(ICON_FA_CHECK " Choose this as the source");
	ImGui::Checkbox("Use this for all items in cart", &isApplyAll);
	_viewModel->IsApplyToAllCartItems(isApplyAll);

	if (clicked)
	{
		if (isApplyAll)
		{
			ImGui::OpenPopup("Are you sure?##ApplyAll");
		}
		else
		{
			ImGui::OpenPopup("Are you sure?##ApplyToSelectedItem");
		}
	}

	ImGui::OkCancelPopupModel("Are you sure?##ApplyAll", ICON_FA_QUESTION_CIRCLE, {
		                          "Change to buy every items in cart from",
		                          sourceName + "?"
	                          }, [&]()
	                          {
		                          _viewModel->ApplySelectedSourceCommand();
	                          }, "Yes", "No");

	ImGui::OkCancelPopupModel("Are you sure?##ApplyToSelectedItem", ICON_FA_QUESTION_CIRCLE, {
		                          "Change to buy " + itemName + " from",
		                          sourceName + "?"
	                          }, [&]()
	                          {
		                          _viewModel->ApplySelectedSourceCommand();
	                          }, "Yes", "No");
}

void SelectSourceView::RenderMaster()
{
	ImGui::BeginChildWithBottomSpace("Master", 2);
	{
		int index = 0;
		for (auto&& itemSource : _viewModel->ItemSources())
		{
			Item item = itemSource.Item();
			Source source = itemSource.Source();
			std::string name = source.Name() + "##" + std::to_string(index);

			if (ImGui::Selectable(name.c_str(),
			                      _viewModel->SelectedIndex() && (index == _viewModel->SelectedIndex().value())))
			{
				_viewModel->SelectedIndex(index);
			}

			if (ImGui::IsItemHovered())
			{
				ImGui::BeginTooltip();

				double price = itemSource.Price();
				ImGui::Text(formatCurrency(price, "Price per unit").c_str());

				ImGui::EndTooltip();
			}
			index++;
		}
	}
	ImGui::EndChild();
	RenderSortByButtons();
	RenderSearchBox();
}

void SelectSourceView::RenderDetails()
{
	ItemSource itemSource = _viewModel->SelectedItem().value();
	Item item = itemSource.Item();
	Source source = itemSource.Source();

	ImGui::BeginChildWithBottomSpace("Details", 2);
	{
		ImGui::TextBoldNormal("Buying from:");
		ImGui::TextLightTitle1(source.Name());
		ImGui::Separator();

		ImGui::TextBoldNormal("Price per unit:");
		ImGui::TextLightTitle2(formatCurrency(itemSource.Price()));

		RenderApplyButton();
	}
	ImGui::EndChild();
}
