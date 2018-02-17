#include "Graphical.h"
#include <iostream>

Graphics::Graphics(Window& window)
	:m_window(window)
{
}

void Graphics::drawquad(glm::vec2 position, float width, float height, glm::vec4 color)
{
	std::vector<float> vertexPositions = {
		position.x - width, position.y - height,
		position.x + width, position.y - height,
		position.x - width, position.y + height,
		position.x + width, position.y + height
	};

	std::vector<float> colors = {
		color.r, color.g, color.b, color.a,
		color.r, color.g, color.b, color.a,
		color.r, color.g, color.b, color.a,
		color.r, color.g, color.b, color.a,
	};

	GuiEntity* entity = new GuiEntity(vertexPositions, colors);
	m_guiRenderer.renderGUI(*entity);
	delete(entity);
}

