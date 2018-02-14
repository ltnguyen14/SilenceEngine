#pragma once
#include "System.h"

class InputSystem : public System
{
public:
	InputSystem(MessageBus* messageBus) : System(messageBus) {}

	void update() {
		// Handle mouse input

		// Handle keyboard input
		
	}

private:
	void onNotify(Message message)
	{
		if (message.getType() == CHAT) {
			std::cout << "INnputSystem: Got CHAT message" << std::endl;
		}
	}
};