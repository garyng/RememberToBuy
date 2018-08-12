#pragma once
#include <examples/imgui_impl_glfw.h>
#include <examples/imgui_impl_opengl3.h>
#include <GL/gl3w.h>
#include <GLFW/glfw3.h>

class App
{
private:
	GLFWwindow* _window;
	const std::string WINDOW_TITLE = "Remember To Buy";
	void Initialize();
	void Loop();
	void Render() const;

public:
	void Start();
};
