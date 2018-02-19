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

private:
	void onNotify(Message message) {
	}
};