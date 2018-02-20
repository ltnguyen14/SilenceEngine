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
	
	void getMousePos(double& x, double& y);
	bool keyPressed(unsigned int keycode) const;
	bool mouseButtonPressed(unsigned int button) const;

private:
	void onNotify(Message message) {
	}
};