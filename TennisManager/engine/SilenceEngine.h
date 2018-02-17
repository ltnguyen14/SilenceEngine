#pragma once
#include "System/EngineSystems.h"

class SilenceEngine {
public:
	SilenceEngine(int width, int height, std::string title);
	~SilenceEngine();

	void update() {
		m_renderSystem->update();
		m_inputSystem->update();
	}

private:
	Window m_window;
	MessageBus * m_messageBus = new MessageBus;
	RenderSystem* m_renderSystem = new RenderSystem(m_messageBus, m_window);
	InputSystem* m_inputSystem = new InputSystem(m_messageBus, m_window);
};