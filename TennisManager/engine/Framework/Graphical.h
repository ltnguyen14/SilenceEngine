#pragma once
#include <string>

#include "Window.h"
#include "Renderers/GUIRenderer.h"
#include "../ResManager/ResManager.h"

class Graphics {
public:
	Graphics(Window& window, ResManager& resManager);

	void clearWindow() { m_window.clear(); };
	void updateWindow() { m_window.update(); };

	void drawquad(glm::vec2 position, float width, float height, glm::vec4 color, std::string textureName);

private:
	Window m_window;
	GUIRenderer m_guiRenderer;
	ResManager m_resManager;
};
