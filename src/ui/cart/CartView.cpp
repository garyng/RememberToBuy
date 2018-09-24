#include "stdafx.h"
#include "CartView.h"

CartView::CartView(const std::shared_ptr<CartViewModel>& viewModel,
                   const std::shared_ptr<ILogger>& logger): ViewBase<CartViewModel>(viewModel, logger)
{
}

std::string CartView::Name() const
{
	return NAMEOF(CartView);
}

void CartView::Render()
{
	ImGui::BeginDefaultCenteredResizableWindow("Cart");
	RenderGoBackButton();


	if (_viewModel->CartItems().empty())
	{
		if (_viewModel->IsSearching())
		{
			ImGui::Columns(2);
			RenderSearchNoResults();
			ImGui::NextColumn();
			ImGui::NoItemSelectedPrompt("NoItemSelected");
		}
		else
		{
			RenderNoCartItems();
		}
	}
	else
	{
		ImGui::Columns(2);

		RenderCartItemList();

		ImGui::NextColumn();

		if (_viewModel->SelectedCartItem())
		{
			RenderCartItemDetails();
		}

		else
		{
			ImGui::NoItemSelectedPrompt("NoItemSelected");
		}
	}


	ImGui::End();
}

void CartView::RenderGoToSelectItemButton()
{
	if (ImGui::FullWidthButton(ICON_FA_PLUS " Add item"))
	{
		_viewModel->GoToSelectItemCommand();
	}
}

void CartView::RenderSearchNoResults()
{
	ImGui::BeginChildWithBottomSpace("NoResult", 3);
	{
		ImGui::BlankScreenPrompt(ICON_FA_SPLOTCH, {"No result..."});
	}
	ImGui::EndChild();
	RenderSortByButtons();
	RenderSearchBox();
	RenderGoToSelectItemButton();
}

void CartView::RenderNoCartItems()
{
	ImGui::BeginChildWithBottomSpace("NoCartItems", 1);

	ImGui::BlankScreenPrompt(ICON_FA_ROBOT, {"Such emptiness", "Try adding some items to the cart?"});

	ImGui::EndChild();

	RenderGoToSelectItemButton();
}

void CartView::RenderCartItemList()
{
	double totalPrice = 0;
	ImGui::BeginChildWithBottomSpace("CartItemList", 4);
	{
		int index = 0;
		for (auto&& cartItem : _viewModel->CartItems())
		{
			Item item = cartItem.Item();
			ItemSource itemSource = cartItem.ItemSource();
			std::string name = item.Name() + "##" + std::to_string(index);

			if (ImGui::Selectable(name.c_str(),
			                      _viewModel->SelectedIndex() && (index == _viewModel->SelectedIndex().value())))
			{
				_viewModel->SelectedIndex(index);
			}
			if (ImGui::IsItemHovered())
			{
				ImGui::BeginTooltip();

				int quantity = cartItem.Quantity();
				double price = itemSource.Price();
				double subTotal = quantity * price;
				std::string sourceName = cartItem.Source().Value().Name();

				ImGui::Text(("Buying from " + sourceName).c_str());
				ImGui::Text(("Quantity: " + std::to_string(quantity)).c_str());
				ImGui::Text(formatCurrency(price, "Price").c_str());
				ImGui::Text(formatCurrency(subTotal, "Subtotal").c_str());

				ImGui::EndTooltip();
			}
			index++;
			totalPrice += cartItem.Quantity() * cartItem.ItemSource().Value().Price();
		}
	}
	ImGui::EndChild();

	ImGui::Spacing();
	ImGui::Text(formatCurrency(totalPrice, "Total").c_str());


	RenderSortByButtons();
	RenderSearchBox();
	RenderGoToSelectItemButton();
}

void CartView::RenderSortByButtons()
{
	for (auto field : CartItemFields::_values())
	{
		if (ImGui::RadioButton((+field)._to_string(), _viewModel->CartItemSortKey() == field))
		{
			_viewModel->CartItemSortKey(field);
		}
		ImGui::SameLine();
	}

	bool isAscending = _viewModel->IsAscending();
	ImGui::CheckButton(
		(isAscending ? ICON_FA_LONG_ARROW_ALT_DOWN " Ascending" : ICON_FA_LONG_ARROW_ALT_UP " Descending"),
		&isAscending);
	_viewModel->IsAscending(isAscending);
}

void CartView::RenderSearchBox()
{
	char searchStringBuffer[255];
	FillCharBuffer(searchStringBuffer, 255, _viewModel->SearchString());

	if (ImGui::InputText(ICON_FA_SEARCH " Filter by", searchStringBuffer, IM_ARRAYSIZE(searchStringBuffer)))
	{
		_viewModel->SearchString(searchStringBuffer);
	}
}

void CartView::RenderCartItemDetails()
{
	auto selectedItem = _viewModel->SelectedCartItem();
	CartItem cartItem = selectedItem.value();
	Item item = cartItem.Item();
	Category category = item.Category();
	Source source = cartItem.Source();
	ItemSource itemSource = cartItem.ItemSource();

	ImGui::BeginChildWithBottomSpace("CartItemDetails", 2);
	{
		ImGui::TextLightTitle1(item.Name());

		ImGui::TextColored(Colors::Grey500, category.Name().c_str());

		ImGui::Separator();

		ImGui::TextBoldNormal("Buying from:");

		ImGui::TextLightTitle2(source.Name());

		if (ImGui::FullWidthButton(ICON_FA_STORE " Change source"))
		{
			_viewModel->GoToSelectSourceCommand();
		}

		ImGui::TextBoldNormal("Price per unit:");

		ImGui::Text(formatCurrency(itemSource.Price()).c_str());


		int quantity = cartItem.Quantity();
		ImGui::TextBoldNormal("Quantity:");

		if (ImGui::FullWidthInputInt("", quantity))
		{
			_viewModel->UpdateCartItemQuantityCommand(cartItem.Id(), quantity);
		}

		ImGui::TextBoldNormal("Subtotal: ");
		double subtotal = cartItem.Quantity() * itemSource.Price();

		ImGui::TextLightTitle2(formatCurrency(subtotal));
	}
	ImGui::EndChild();


	if (ImGui::FullWidthButton(ICON_FA_CHECK " Check off"))
	{
		ImGui::OpenPopup("Are you sure?##CheckOffItem");
	}
	if (ImGui::FullWidthButton(ICON_FA_MINUS " Remove"))
	{
		ImGui::OpenPopup("Are you sure?##RemoveItem");
	}

	ImGui::OkCancelPopupModel("Are you sure?##RemoveItem", ICON_FA_EXCLAMATION_CIRCLE, {
		                          "Removing \"" + item.Name() + "\" from list",
		                          "Are you sure?"
	                          }, [&]()
	                          {
		                          _viewModel->RemoveSelectedCartItemCommand();
	                          }, "Yes", "No");

	ImGui::OkCancelPopupModel("Are you sure?##CheckOffItem", ICON_FA_CHECK_CIRCLE, {
		                          "Checking off \"" + item.Name() + "\"",
		                          "Are you sure?"
	                          }, [&]()
	                          {
		                          _viewModel->CheckOffSelectedCartItemCommand();
	                          }, "Yes", "No");
}
