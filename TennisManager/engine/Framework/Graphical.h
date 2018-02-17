#pragma once
#include <string>

#include "Window.h"
#include "Renderers/GUIRenderer.h"

class Graphics {
public:
	Graphics(Window& window);

	void clearWindow() { m_window.clear(); };
	void updateWindow() { m_window.update(); };

	void drawquad(glm::vec2 position, float width, float height, glm::vec4 color);

private:
	Window m_window;
	GUIRenderer m_guiRenderer;
};
