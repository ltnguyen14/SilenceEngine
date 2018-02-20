#include "Window.h"

void cursor_position_callback(GLFWwindow * window, double xpos, double ypos)
{
	Window* win = (Window*)glfwGetWindowUserPointer(window);
	win->mx = xpos;
	win->my = ypos;
}

void mouse_button_callback(GLFWwindow * window, int button, int action, int mods)
{
	Window* win = (Window*)glfwGetWindowUserPointer(window);
	win->m_Buttons[button] = action != GLFW_RELEASE;
}

void key_callback(GLFWwindow * window, int key, int scancode, int action, int mods)
{
	Window* win = (Window*)glfwGetWindowUserPointer(window);
	win->m_Keys[key] = action != GLFW_RELEASE;
}


Window::Window(int width, int height, std::string title)
	:m_width(width), m_height(height), m_title(title)
{
	if (!init()) {
		glfwTerminate();
		return;
	}
	for (int i = 0; i < MAX_BUTTON; i++)
	{
		m_Buttons[i] = false;
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
	glfwSetWindowUserPointer(m_window, this);
	glfwSwapInterval(0);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glfwSetMouseButtonCallback(m_window, mouse_button_callback);
	glfwSetCursorPosCallback(m_window, cursor_position_callback);
	glfwSetKeyCallback(m_window, key_callback);


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

bool Window::keyPressed(unsigned int keycode) const
{
	if (keycode >= MAX_KEY)
		return false;

	return m_Keys[keycode];
}

bool Window::mouseButtonPressed(unsigned int button) const
{
	if (button >= MAX_BUTTON)
		return false;

	return m_Buttons[button];
}
