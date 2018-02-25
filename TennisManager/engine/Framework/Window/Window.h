#pragma once
#include <string>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define MAX_BUTTON 32
#define MAX_KEY 1024

class Window {
public:
	Window(int width, int height, std::string title);
	~Window();

	bool init();
	void clear() const;
	void update() const;
	void setPosition(double x, double y) { glfwSetCursorPos(m_window, x, y); };

	inline bool isRunning() { return !glfwWindowShouldClose(m_window); };
	inline void getMousePos(double& x, double& y) { x = mx; y = my; };
	inline int getWidth() { return m_width; };
	inline int getHeight() { return m_height; };

	bool keyPressed(unsigned int keycode) const;
	bool mouseButtonPressed(unsigned int button) const;

private:
	int m_width, m_height;
	double mx, my; // Mouse position
	bool m_Buttons[MAX_BUTTON]; // Mouse buttons
	bool m_Keys[MAX_KEY]; // Keys 

	std::string m_title;
	GLFWwindow* m_window;

private:
	friend static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos); 
	friend static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	friend static void key_callback(GLFWwindow * window, int key, int scancode, int action, int mods);

};