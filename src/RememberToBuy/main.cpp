// RememberToBuy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Hypodermic/ContainerBuilder.h>
#include "ui/Renderer.h"
#include "ui/App.h"
#include "test/ImGuiDemoTestView.h"
#include "logger/ConsoleLogger.h"
#include "test/FontsTestView.h"

using namespace std;
using namespace Hypodermic;

class IResettable
{
	// todo: IResettable
public:
	virtual ~IResettable() = default;
	void virtual Reset() = 0;
};

class TestView : public ITestView
{
public:

	void Render() override
	{
		ImGui::Begin("Testing");
		ImGui::FullWidthButton("asdasd");
		ImGui::Text("Dear ImGui %s", ImGui::GetVersion());
		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate,
		            ImGui::GetIO().Framerate);
		ImGui::Text("%d vertices, %d indices (%d triangles)", ImGui::GetIO().MetricsRenderVertices,
		            ImGui::GetIO().MetricsRenderIndices, ImGui::GetIO().MetricsRenderIndices / 3);
		ImGui::End();
	}

	string Name() const override
	{
		return "TestView";
	}
};

class AnotherView : public IView
{
public:
	string Name() const override
	{
		return "AnotherView";
	}

	void Render() override
	{
		ImGui::Begin("Another view");
		ImGui::End();
	}
};

// https://www.fluentcpp.com/2018/05/18/make-sfinae-pretty-2-hidden-beauty-sfinae/
template <class TDerived, class TBase>
using IsBaseOf = enable_if_t<is_base_of_v<TBase, TDerived>>;

template <class T, class = IsBaseOf<T, IView>>
void test(shared_ptr<T> var)
{
	if constexpr (is_base_of_v<IView, T>)
	{
		// https://stackoverflow.com/questions/13636540/how-to-check-for-the-type-of-a-template-parameter
		const shared_ptr<IView> casted = static_pointer_cast<IView>(var);
		std::cout << casted->GetName();
	}
}

template <class T, class U, class = IsBaseOf<T, IView>, class = enable_if_t<is_arithmetic_v<U>>>
void test2(shared_ptr<T> t1, shared_ptr<U> u1)
{
}

void showAllTestViews(const shared_ptr<Container>& container)
{
	std::vector<std::shared_ptr<ITestView>> testViews = container->resolveAll<ITestView>();
	for (const auto& testView : testViews)
	{
		testView->IsVisible(true);
	}
}


int main(int argc, char* argv[])
{
	ContainerBuilder builder;

	builder.registerType<ConsoleLogger>()
	       .as<ILogger>()
	       .singleInstance();

	builder.registerType<AnotherView>()
	       .as<IView>()
	       .asSelf()
	       .singleInstance();
	builder.registerType<TestView>()
	       .as<ITestView>()
	       .asSelf()
	       .singleInstance();

	builder.registerType<ImGuiDemoTestView>()
	       .as<ITestView>()
	       .asSelf()
	       .singleInstance();
	builder.registerType<FontsTestView>()
	       .as<ITestView>()
	       .asSelf()
	       .singleInstance();

	builder.registerType<Renderer>()
	       .singleInstance();
	builder.registerType<App>()
	       .singleInstance();

	shared_ptr<Container> container = builder.build();
	showAllTestViews(container);

	container->resolve<App>()->Start();


	/*shared_ptr<TestView> view = make_shared<TestView>();
	test(view);

	shared_ptr<int> i = make_shared<int>(1);
	test2(view, i);*/
}
