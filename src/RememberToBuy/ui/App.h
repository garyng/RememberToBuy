#pragma once
#include <examples/imgui_impl_glfw.h>
#include <examples/imgui_impl_opengl3.h>
#include <GL/gl3w.h>
#include <GLFW/glfw3.h>
#include "Renderer.h"


class App
{
private:
	GLFWwindow* _window;
	const std::string WINDOW_TITLE = "Remember To Buy";
	std::shared_ptr<Renderer> _renderer;
	std::shared_ptr<ILogger> _logger;
	void Initialize();
	void Loop() const;
	void Render() const;

public:
	void Start();
	explicit App(const std::shared_ptr<Renderer>& renderer, const std::shared_ptr<ILogger>& logger);
};
