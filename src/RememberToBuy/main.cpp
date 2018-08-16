// RememberToBuy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Hypodermic/ContainerBuilder.h>
#include "App.h"

using namespace std;
using namespace Hypodermic;

class ILogger
{
};

class IResettable
{
public:
	void virtual Reset() = 0;
};

class IView
{
protected:
	bool _isVisible;

public:
	virtual ~IView() = default;
	string virtual Name() const = 0;

	bool IsVisible() const { return _isVisible; }
	void IsVisible(bool value) { _isVisible = value; }


	void virtual Render() = 0;
};

class TestView : public IView
{
public:

	void Render() override
	{
		//;
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
		// 
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

class Dependency
{
public:
	Dependency(const vector<shared_ptr<IView>>& views)
	{
		for (auto&& view : views)
		{
			cout << view->Name();
		}
	}
};

class Renderer
{
private:
	vector<shared_ptr<IView>> _views;

public:
	explicit Renderer(const vector<shared_ptr<IView>>& views)
		: _views(views)
	{
	}

	void Render()
	{
		if (ImGui::BeginMainMenuBar())
		{
			if (ImGui::BeginMenu("Debug"))
			{
				ImGui::Text("Views");
			}
		}
	}
};

int main(int argc, char* argv[])
{
	ContainerBuilder builder;
	builder.registerType<TestView>().as<IView>().asSelf();
	builder.registerType<AnotherView>().as<IView>().asSelf();
	builder.registerType<Dependency>();
	auto container = builder.build();

	container->resolve<Dependency>();

	/*shared_ptr<TestView> testView = container->resolve<TestView>();
	cout << testView->GetName();*/


	/*shared_ptr<TestView> view = make_shared<TestView>();
	test(view);

	shared_ptr<int> i = make_shared<int>(1);
	test2(view, i);*/

	system("pause");

	/*shared_ptr<App> app = make_shared<App>();
	app->Start();*/
}
