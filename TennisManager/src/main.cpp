#include "System/InputSystem.h"
#include "System/RenderSystem.h"

int main() {
	MessageBus messageBus;
	InputSystem compA(&messageBus);
	RenderSystem compB(&messageBus);

	// This is supposed to act like a game loop.
	while(true) {
		compA.update();
		compB.update();
		messageBus.notify();
	}

	return 0;
}