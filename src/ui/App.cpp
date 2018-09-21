#include "stdafx.h"
#include "App.h"

using namespace std;

App::App(const std::shared_ptr<Renderer>& renderer, const std::shared_ptr<ILogger>& logger) : _renderer(renderer),
                                                                                              _logger(logger)
{
}

void App::Start()
{
	_logger->Debug("Initializing ImGui");
	Initialize();
	_logger->Debug("Entering render loop");
	Loop();
	_logger->Debug("Exit from render loop");
}


void App::Initialize()
{
	glfwSetErrorCallback([](int error, const char* description)
	{
		std::cout << "Error " << error << ": " << description << std::endl;
	});

	glfwInit();
	const char* glsl_version = "#version 130";
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);

	_window = glfwCreateWindow(1280, 720, WINDOW_TITLE.c_str(), nullptr, nullptr);

	glfwMakeContextCurrent(_window);
	glfwSwapInterval(1); // Enable vsync
	gl3wInit();

	// Setup Dear ImGui binding
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	(void)io;

	ImGui_ImplGlfw_InitForOpenGL(_window, true);
	ImGui_ImplOpenGL3_Init(glsl_version);

	ImGui::StyleColorsDark();
	LoadFonts();
	SetStyles();
}

void App::LoadFonts() const
{
	_logger->Debug("Loading fonts");
	// Font index is best retrieved via Fonts class
	ImGuiIO& io = ImGui::GetIO();
	io.Fonts->Clear();

	io.Fonts->AddFontFromFileTTF("fonts/Roboto-Regular.ttf", 20.0f);
	AddIconFont(io, 20.0f);

	io.Fonts->AddFontFromFileTTF("fonts/Roboto-Light.ttf", 35.0f);
	AddIconFont(io, 35.0f);

	io.Fonts->AddFontFromFileTTF("fonts/Roboto-Bold.ttf", 20.0f);
	AddIconFont(io, 20.0f);

	io.Fonts->AddFontFromFileTTF("fonts/Roboto-Regular.ttf", 30.0f);
	AddIconFont(io, 30.0f);

	io.Fonts->AddFontFromFileTTF("fonts/Roboto-Light.ttf", 30.0f);
	AddIconFont(io, 30.0f);

	AddIconFont(io, 72.0f, false);

	io.Fonts->AddFontFromFileTTF("fonts/Roboto-Regular.ttf", 15.0f);
	AddIconFont(io, 15.0f);

	io.Fonts->Build();
	_logger->Debug("All fonts loaded");
}


void App::AddIconFont(ImGuiIO& io, float fontSize, bool mergeIntoPrevious) const
{
	ImFontConfig config;
	config.MergeMode = mergeIntoPrevious;
	// make them monospace
	// https://github.com/ocornut/imgui/issues/1869
	config.GlyphMinAdvanceX = fontSize + 5;
	config.GlyphMaxAdvanceX = fontSize + 5;
	static const ImWchar iconRange[] = {ICON_MIN_FA, ICON_MAX_FA, 0};
	io.Fonts->AddFontFromFileTTF("fonts/fa-solid-900.ttf", fontSize, &config, iconRange);
}

void App::SetStyles() const
{
	ImGuiStyle& style = ImGui::GetStyle();
	style.WindowPadding = ImVec2(20, 20);
	style.WindowRounding = 5.0f;
	style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
	style.FramePadding = ImVec2(5, 5);
	style.FrameRounding = 4.0f;
	style.ItemSpacing = ImVec2(12, 8);
	style.ItemInnerSpacing = ImVec2(8, 6);
	style.IndentSpacing = 25.0f;
	style.ScrollbarSize = 15.0f;
}

void App::Loop() const
{
	ImVec4 clearColor = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

	while (!glfwWindowShouldClose(_window))
	{
		glfwPollEvents();
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		Render();
		ImGui::Render();

		int displayWidth, displayHeight;
		glfwMakeContextCurrent(_window);
		glfwGetFramebufferSize(_window, &displayWidth, &displayHeight);
		glViewport(0, 0, displayWidth, displayHeight);
		glClearColor(clearColor.x, clearColor.y, clearColor.z, clearColor.w);
		glClear(GL_COLOR_BUFFER_BIT);
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		glfwMakeContextCurrent(_window);
		glfwSwapBuffers(_window);
	}

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwDestroyWindow(_window);
	glfwTerminate();
}

void App::Render() const
{
	_renderer->Render();
}
