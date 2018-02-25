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
	m_guiRenderer.renderGUI(*entity, m_window);
	delete(entity);
}

void Graphics::drawText(glm::vec2 position, std::string content, float width, glm::vec4 color)
{
	m_textRenderer.AddText(content, position, width, color);
	m_textRenderer.RenderText(m_window);
}

void Graphics::addCube(glm::vec3 position, glm::vec3 scale, const std::string & texture)
{
	m_cubeRenderer.addCube(position, scale, texture);
}

void Graphics::renderCubes(Camera* camera)
{
	m_cubeRenderer.renderCubes(m_window, camera);
}

Player * Graphics::createPlayer()
{
	m_camera->hookEntity(*m_player);
	return m_player;
}


