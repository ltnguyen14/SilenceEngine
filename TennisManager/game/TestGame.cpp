#include "TestGame.h"

int main() {
	GameState testGame(1280, 720, "Test Game");
	while (true) {
		testGame.update();
	}
}