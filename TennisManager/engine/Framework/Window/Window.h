#pragma once
#include <string>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define MAX_BUTTON 32

class Window {
public:
	Window(int width, int height, std::string title);
	~Window();

	bool init();
	void clear() const;
	void update() const;

	inline bool isRunning() { return !glfwWindowShouldClose(m_window); };
	inline void getMousePos(double& x, double& y) { x = mx; y = my; };

private:
	int m_width, m_height;
	double mx, my; // Mouse position
	bool m_Buttons[MAX_BUTTON]; // Mouse buttons
	std::string m_title;
	GLFWwindow* m_window;

private:
	friend static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
	friend static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

};