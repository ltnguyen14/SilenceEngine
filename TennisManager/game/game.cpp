#include "StateManager.h"
#include "GameStates/IntroState.h"

int main() {
	StateManager testGame(1280, 720, "Pong");
	IntroState* introState = new IntroState(&testGame);
	testGame.pushState(introState);

	while (testGame.isRunning()) {
		testGame.handleEvents();
		testGame.update();
		testGame.draw();
	}
}
