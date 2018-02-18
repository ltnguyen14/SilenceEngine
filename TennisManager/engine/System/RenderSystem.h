#pragma once
#include <string>
#include "System.h"
#include "../Framework/Framework.h"

class RenderSystem : public System
{
public:
	RenderSystem(MessageBus* messageBus, Window& window, ResManager& resManager) : System(messageBus, window, resManager) {
		std::cout << "Initialize Render System" << std::endl;
	}

	void update()
	{
		m_graphics.updateWindow();
		m_graphics.clearWindow();
		m_graphics.drawquad({ 0.0f, 0.0f }, 0.5, 0.5, { 0.2, 0.4, 0.8, 0.0 }, "arrow-right.png");
	}

private:
	void onNotify(Message message)
	{
	}
};