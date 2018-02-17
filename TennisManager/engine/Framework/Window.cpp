#include "Window.h"

Window::Window(int width, int height, std::string title)
	:m_width(width), m_height(height), m_title(title)
{
	if (!init()) {
		glfwTerminate();
		return;
	}
}

Window::~Window()
{
	glfwTerminate();
}

bool Window::init()
{
	if (!glfwInit()) {
		std::cout << "Failed to initialize GLFW!" << std::endl;
		return false;
	}
	else
		std::cout << "GLFW initialized" << std::endl;

	// Create window
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), NULL, NULL);
	if (!m_window) {
		glfwTerminate();
		std::cout << "Error initializing window" << std::endl;
		return false;
	}
	else
		std::cout << "Window created!" << std::endl;

	// Make current context
	glfwMakeContextCurrent(m_window);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	// Initialize glew
	if (glewInit() != GLEW_OK) {
		std::cout << "GLEW Error!" << std::endl;
	}
	else {
		std::cout << "Glew init success!" << std::endl;
	};

	std::cout << "GL Version: " << glGetString(GL_VERSION) << std::endl;

	return true;
}

void Window::clear() const
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::update() const
{
	glfwPollEvents();
	glfwSwapBuffers(m_window);
}
