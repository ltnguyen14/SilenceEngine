#pragma once
#include "System/EngineSystems.h"

class SilenceEngine {
public:
	SilenceEngine(int width, int height, std::string title);
	~SilenceEngine();

	void update() {
		m_renderSystem->update();
		m_inputSystem->update();

		m_messageBus->notify();
	}

	void drawQuad(glm::vec2 position, float width, float height, glm::vec4 color, std::string textureName);

	inline bool isRunning() { return m_window->isRunning(); };

private:
	Window * m_window;
	ResManager m_resManager;
	MessageBus * m_messageBus = new MessageBus;
	RenderSystem* m_renderSystem = new RenderSystem(m_messageBus, m_window, m_resManager);
	InputSystem* m_inputSystem = new InputSystem(m_messageBus, m_window, m_resManager);
};