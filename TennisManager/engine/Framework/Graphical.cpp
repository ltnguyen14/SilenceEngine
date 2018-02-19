#include "Graphical.h"
#include <iostream>

Graphics::Graphics(Window* window, ResManager& resManager)
	:m_window(window), m_resManager(resManager)
{
}

void Graphics::drawquad(glm::vec2 position, float width, float height, glm::vec4 color, std::string textureName)
{
	std::vector<float> vertexPositions = {
		position.x - width, position.y + height,
		position.x - width, position.y - height,
		position.x + width, position.y + height,
		position.x + width, position.y - height,
	};

	GuiEntity* entity = new GuiEntity(vertexPositions, color, m_resManager.getTexture(textureName));
	m_guiRenderer.renderGUI(*entity);
	delete(entity);
}

