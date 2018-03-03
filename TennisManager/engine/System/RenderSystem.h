#pragma once
#include <string>
#include "System.h"
#include "../Framework/Framework.h"

class RenderSystem : public System
{
public:
	RenderSystem(MessageBus* messageBus, Window* window, ResManager& resManager) : System(messageBus, window, resManager) {
		std::cout << "Initialize Render System" << std::endl;
	}

	void update() {
		m_graphics.updateWindow();
		m_graphics.clearWindow();
	}

	void drawQuad(glm::vec2 position, float width, float height, glm::vec4 color, std::string textureName) {
		m_graphics.drawquad(position, width, height, color, textureName);
	}

	void renderText(glm::vec2 position, std::string content, float width, glm::vec4 color) {
		m_graphics.drawText(position, content, width, color);
	}

	void addChunk(glm::vec3 position, glm::vec3 scale, const std::string& material) {
		m_graphics.addChunk(position, scale, material);
	}

	void createTerrain(unsigned int height, glm::vec3 position) {
		m_graphics.createTerrain(height, position);
	}

	void renderChunks(Camera* camera) {
		m_graphics.renderChunks(camera);
	}

	Player* createPlayer() { return m_graphics.createPlayer(); };
	Camera* getCamera() { return m_graphics.getCamera(); };

private:
	void onNotify(Message message) {
	}
};