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
#include "ui/pending/PendingView.h"
#include "ui/history/HistoryView.h"
#include "ui/stock/StockView.h"

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
          class = IsBaseOf<TViewModel, IViewModel>>
void registerViewViewModel(ContainerBuilder& builder)
{
	builder.registerType<TView>()
	       .as<ViewBase<TViewModel>>()
	       .as<IView>()
	       .asSelf()
	       .singleInstance();

	builder.registerType<TViewModel>()
	       .as<IViewModel>()
	       .asSelf()
	       .singleInstance();
}

int main(int argc, char* argv[])
{
	std::shared_ptr<int> s = make_shared<int>();

	ContainerBuilder builder;

	builder.registerType<ConsoleLogger>()
	       .as<ILogger>()
	       .singleInstance();
	builder.registerType<NavigationService>()
	       .singleInstance();

	registerViewViewModel<CartView, CartViewModel>(builder);
	registerViewViewModel<PendingView, PendingViewModel>(builder);
	registerViewViewModel<HistoryView, HistoryViewModel>(builder);
	registerViewViewModel<StockView, StockViewModel>(builder);

	registerTestView<ImGuiDemoTestView>(builder);
	registerTestView<FontsTestView>(builder);
	registerTestView<ColorsTestView>(builder);
	registerTestView<NavigationTestView>(builder);


	builder.registerType<Renderer>()
	       .singleInstance();
	builder.registerType<App>()
	       .singleInstance();

	shared_ptr<Container> container = builder.build();

	showAllTestViews(container);

	container->resolve<NavigationService>()->GoTo<CartViewModel>();
	container->resolve<App>()->Start();
}
