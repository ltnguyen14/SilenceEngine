#include "System/InputSystem.h"
#include "System/RenderSystem.h"
#include "System/GameLogicSystem.h"


int main() {
	MessageBus messageBus;
	InputSystem inputSystem(&messageBus);
	RenderSystem renderSystem(&messageBus);
	GameLogicSystem gameLogic(&messageBus);

	// This is supposed to act like a game loop.
	while(true) {
		inputSystem.update();
		renderSystem.update();
		gameLogic.update();
		messageBus.notify();
	}

	return 0;
}