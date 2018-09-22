#include "stdafx.h"
#include "CartView.h"
#include <addons/imguivariouscontrols/imguivariouscontrols.h>

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
			RenderNoCartItemSelected();
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

		if (_viewModel->SelectedCartItem().has_value())
		{
			RenderCartItemDetails();
		}

		else
		{
			RenderNoCartItemSelected();
		}
	}


	ImGui::End();
}

void CartView::RenderGoToPendingButton()
{
	ImGui::FullWidthButton("Check pending items " ICON_FA_ANGLE_DOUBLE_RIGHT);
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
	RenderGoToPendingButton();
}

void CartView::RenderNoCartItems()
{
	ImGui::BeginChildWithBottomSpace("NoCartItems", 1);

	ImGui::BlankScreenPrompt(ICON_FA_ROBOT, {"Such emptiness", "Try moving some pending items to the cart?"});

	ImGui::EndChild();

	RenderGoToPendingButton();
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
			if (ImGui::Selectable(item.Name().c_str(),
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
	RenderGoToPendingButton();
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
	ImGui::CheckButton((isAscending ? ICON_FA_SORT_DOWN " Ascending" : ICON_FA_SORT_UP " Descending"), &isAscending);
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

void CartView::RenderNoCartItemSelected()
{
	ImGui::BeginChild("NoItemSelected");

	ImGui::BlankScreenPrompt(ICON_FA_HAND_POINT_LEFT, {"Select one item to for its details"});

	ImGui::EndChild();
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

		if (ImGui::FullWidthButton(ICON_FA_STORE " Change store"))
		{
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
	}
	if (ImGui::FullWidthButton(ICON_FA_MINUS " Remove"))
	{
	}
}
