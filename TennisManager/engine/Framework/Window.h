#pragma once
#include <string>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Window {
public:
	Window(int width, int height, std::string title);
	~Window();

	bool init();
	void clear() const;
	void update() const;

private:
	int m_width, m_height;
	std::string m_title;
	GLFWwindow* m_window;
};