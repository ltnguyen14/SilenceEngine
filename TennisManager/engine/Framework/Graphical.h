#pragma once
#include <string>

#include "Window.h"

class Graphics {
public:
	Graphics(Window& window);

	void clearWindow() { m_window.clear(); };
	void updateWindow() { m_window.update(); };


private:
	Window m_window;
};
