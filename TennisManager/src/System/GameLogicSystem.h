#pragma once
#include "System.h"

class GameLogicSystem : public System
{
public:
	GameLogicSystem(MessageBus* messageBus) : System(messageBus) {}

	void update()
	{
		// Handle game logic
	}

private:
	void onNotify(Message message)
	{
		if (message.getType() == CHAT) {
			std::cout << "Game Logic: " << message.getEvent() << std::endl;
		}
	}
};