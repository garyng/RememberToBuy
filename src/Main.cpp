// RememberToBuy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Hypodermic/ContainerBuilder.h>
#include "ui/Renderer.h"
#include "ui/App.h"
#include "ui/test/ImGuiDemoTestView.h"
#include "logger/ConsoleLogger.h"
#include "ui/test/FontsTestView.h"
#include "ui/test/ColorsTestView.h"
#include "ui/cart/CartView.h"
#include "ui/IViewModel.h"
#include "ui/cart/CartViewModel.h"
#include "ui/navigation/NavigationService.h"
#include "ui/test/NavigationTestView.h"
#include "ui/history/HistoryView.h"
#include "storage/CartItemStorage.h"
#include "storage/CategoryStorage.h"
#include "storage/HistoryItemStorage.h"
#include "storage/ItemStorage.h"
#include "storage/ItemSourceStorage.h"
#include "storage/SourceStorage.h"
#include "ui/test/StorageTestView.h"
#include "proxy/ProxyFactory.h"
#include "query/GetAllCartItemsQueryHandler.h"
#include "query/GetItemByIdQueryHandler.h"
#include "query/GetCategoryByIdQueryHandler.h"
#include "command/UpdateCartItemQuantityCommandHandler.h"
#include "query/GetItemSourceByItemIdAndSourceIdQueryHandler.h"
#include "query/GetSourceByIdQueryHandler.h"
#include "ui/test/IconsAlignmentTestView.h"
#include "ui/test/ICanResetTestView.h"
#include "command/RemoveCartItemCommandHandler.h"
#include "command/CheckOffCartItemCommandHandler.h"
#include "ui/dashboard/DashboardView.h"
#include "query/GetAllHistoryItems.h"
#include "query/GetAllHistoryItemsQueryHandler.h"
#include "ui/cart/SelectSourceView.h"
#include "query/GetAllItemSourcesByItemIdQueryHandler.h"
#include "command/UpdateSourceByCartItemIdCommandHandler.h"
#include "command/UpdateSourceOfAllCartItemsCommandHandler.h"
#include "ui/cart/SelectItemView.h"
#include "query/GetAllItems.h"
#include "query/GetAllItemsQueryHandler.h"
#include "query/GetBestSourceByItemIdQueryHandler.h"
#include "command/AddCartItemCommandHandler.h"


using namespace std;
using namespace Hypodermic;

void showAllTestViews(const shared_ptr<Container>& container)
{
	std::vector<std::shared_ptr<ITestView>> testViews = container->resolveAll<ITestView>();
	for (const auto& testView : testViews)
	{
		testView->IsVisible(true);
	}
}

template <class TView,
          class = IsBaseOf<TView, IView>>
void registerTestView(ContainerBuilder& builder)
{
	builder.registerType<TView>()
	       .as<ITestView>()
	       .asSelf()
	       .singleInstance();
}

template <class TView, class TViewModel,
          class = IsBaseOf<TView, ViewBase<TViewModel>>,
          class = std::enable_if_t<
	          std::is_base_of_v<IViewModel, TViewModel> ||
	          (std::is_base_of_v<IViewModel, TViewModel> && std::is_base_of_v<ICanReset, TViewModel>)>>
void registerViewViewModel(ContainerBuilder& builder)
{
	builder.registerType<TView>()
	       .as<ViewBase<TViewModel>>()
	       .as<IView>()
	       .asSelf()
	       .singleInstance();

	if constexpr (std::is_base_of_v<ICanReset, TViewModel>)
	{
		builder.registerType<TViewModel>()
		       .as<IViewModel>()
		       .as<ICanReset>()
		       .asSelf()
		       .singleInstance();
	}
	else
	{
		builder.registerType<TViewModel>()
		       .as<IViewModel>()
		       .asSelf()
		       .singleInstance();
	}
}

template <class TStorage, class = IsBaseOf<TStorage, IStorage>>
void registerStorage(ContainerBuilder& builder)
{
	builder.registerType<TStorage>()
	       .as<IStorage>()
	       .asSelf()
	       .singleInstance();
}

template <class TQueryHandler, class TQuery, class TResult,
          class = IsBaseOf<TQueryHandler, IQueryHandler<TQuery, TResult>>>
void registerQuery(ContainerBuilder& builder)
{
	builder.registerType<TQueryHandler>()
	       .as<IQueryHandler<TQuery, TResult>>();
}

template <class TCommandHandler, class TCommand,
          class = IsBaseOf<TCommandHandler, ICommandHandler<TCommand>>>
void registerCommand(ContainerBuilder& builder)
{
	builder.registerType<TCommandHandler>()
	       .as<ICommandHandler<TCommand>>();
}


int main(int argc, char* argv[])
{
	ContainerBuilder builder;

	builder.registerType<ConsoleLogger>()
	       .as<ILogger>()
	       .singleInstance();
	builder.registerType<NavigationService>()
	       .singleInstance();

	registerViewViewModel<CartView, CartViewModel>(builder);
	registerViewViewModel<HistoryView, HistoryViewModel>(builder);
	registerViewViewModel<DashboardView, DashboardViewModel>(builder);
	registerViewViewModel<SelectSourceView, SelectSourceViewModel>(builder);
	registerViewViewModel<SelectItemView, SelectItemViewModel>(builder);

	registerTestView<ImGuiDemoTestView>(builder);
	registerTestView<FontsTestView>(builder);
	registerTestView<ColorsTestView>(builder);
	registerTestView<NavigationTestView>(builder);
	registerTestView<StorageTestView>(builder);
	registerTestView<IconAlignmentTestView>(builder);
	registerTestView<ICanResetTestView>(builder);

	registerStorage<CartItemStorage>(builder);
	registerStorage<CategoryStorage>(builder);
	registerStorage<HistoryItemStorage>(builder);
	registerStorage<ItemStorage>(builder);
	registerStorage<ItemSourceStorage>(builder);
	registerStorage<SourceStorage>(builder);

	builder.registerType<Renderer>()
	       .singleInstance();
	builder.registerType<App>()
	       .singleInstance();

	builder.registerType<QueryDispatcher>()
	       .singleInstance();
	builder.registerType<CommandDispatcher>()
	       .singleInstance();

	builder.registerType<ProxyFactory>()
	       .singleInstance();

	registerQuery<GetAllCartItemsQueryHandler, GetAllCartItems, std::vector<CartItem>>(builder);
	registerQuery<GetAllHistoryItemsQueryHandler, GetAllHistoryItems, std::vector<HistoryItem>>(builder);
	registerQuery<GetAllItemSourcesByItemIdQueryHandler, GetAllItemSourcesByItemId, std::vector<ItemSource>>(builder);
	registerQuery<GetAllItemsQueryHandler, GetAllItems, std::vector<Item>>(builder);
	registerQuery<GetItemByIdQueryHandler, GetItemById, Item>(builder);
	registerQuery<GetCategoryByIdQueryHandler, GetCategoryById, Category>(builder);
	registerQuery<GetItemSourceByItemIdAndSourceIdQueryHandler, GetItemSourceByItemIdAndSourceId, ItemSource>(builder);
	registerQuery<GetSourceByIdQueryHandler, GetSourceById, Source>(builder);
	registerQuery<GetBestSourceByItemIdQueryHandler, GetBestSourceByItemId, ItemSource>(builder);

	registerCommand<UpdateCartItemQuantityCommandHandler, UpdateCartItemQuantity>(builder);
	registerCommand<UpdateSourceByCartItemIdCommandHandler, UpdateSourceByCartItemId>(builder);
	registerCommand<UpdateSourceOfAllCartItemsCommandHandler, UpdateSourceOfAllCartItems>(builder);
	registerCommand<RemoveCartItemCommandHandler, RemoveCartItem>(builder);
	registerCommand<CheckOffCartItemCommandHandler, CheckOffCartItem>(builder);
	registerCommand<AddCartItemCommandHandler, AddCartItem>(builder);

	shared_ptr<Container> container = builder.build();

	// showAllTestViews(container);

	container->resolve<NavigationService>()->GoTo<DashboardViewModel>();
	// container->resolve<NavigationService>()->GoTo<CartViewModel>();
	container->resolve<App>()->Start();
}
