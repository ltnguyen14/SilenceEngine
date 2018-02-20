#include "TestGame.h"

int main() {
	GameState testGame(1280, 720, "Pong");
	while (testGame.isRunning()) {
		testGame.update();
	}
}
