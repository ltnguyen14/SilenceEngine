#pragma once
#include <string>
#include "System.h"
#include "../Framework/Framework.h"

class RenderSystem : public System
{
public:
	RenderSystem(MessageBus* messageBus, Window& window) : System(messageBus, window) {
		std::cout << "Initialize Render System" << std::endl;
	}

	void update()
	{
		m_graphics.updateWindow();
		m_graphics.clearWindow();
	}

private:
	void onNotify(Message message)
	{
	}
};