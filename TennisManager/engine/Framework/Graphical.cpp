#include "Graphical.h"
#include <iostream>

Graphics::Graphics(Window* window, ResManager& resManager)
	:m_window(window), m_resManager(resManager), m_terrainGenerator(&m_chunkRenderer)
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

void Graphics::addChunk(glm::vec3 position, glm::vec3 scale, const std::string& material)
{
	m_chunkRenderer.addChunk(position, scale, material, &m_resManager);
}

void Graphics::renderChunks(Camera* camera)
{
	m_chunkRenderer.renderChunks(m_window, camera);
}

void Graphics::createTerrain(unsigned int height, glm::vec3 position)
{
	m_terrainGenerator.createTerrain(height, position, &m_resManager);
}

Player * Graphics::createPlayer()
{
	m_camera->hookEntity(*m_player);
	return m_player;
}


