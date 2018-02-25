#pragma once
#include <string>

#include "Window/Window.h"
#include "Renderers/GUIRenderer.h"
#include "Renderers/TextRenderer.h"
#include "Renderers/CubeRenderer.h"
#include "../ResManager/ResManager.h"

class Graphics {
public:
	Graphics(Window* window, ResManager& resManager);

	void clearWindow() { m_window->clear(); };
	void updateWindow() { m_window->update(); };

	void drawquad(glm::vec2 position, float width, float height, glm::vec4 color, std::string textureName);
	void drawText(glm::vec2 position, std::string content, float width, glm::vec4 color);

	void addCube(glm::vec3 position, glm::vec3 scale, const std::string& texture);
	void renderCubes();

private:
	Window* m_window;
	GUIRenderer m_guiRenderer;
	TextRenderer m_textRenderer;
	ResManager m_resManager;
	CubeRenderer m_cubeRenderer;
};
