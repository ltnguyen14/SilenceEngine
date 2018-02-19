#pragma once
#include "System.h"

class InputSystem : public System
{
public:
	InputSystem(MessageBus* messageBus, Window* window, ResManager& resManager) : System(messageBus, window, resManager) {
		std::cout << "Initialize Input System" << std::endl;
	}

	void update() {
		// Handle mouse input
		// Handle keyboard input
		
	}

private:
	void onNotify(Message message) {
	}
};