#include "../engine/GameSkeleton/StateManager.h"
#include "GameStates/IntroState.h"

int main() {
	StateManager minecraft(1280, 720, "Minecraft");
	IntroState* introState = new IntroState(&minecraft);
	minecraft.pushState(introState);

	while (minecraft.isRunning()) {
		minecraft.handleEvents();
		minecraft.update();
		minecraft.draw();
	}
}