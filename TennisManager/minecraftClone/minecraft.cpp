#include "../engine/GameSkeleton/StateManager.h"
#include "GameStates/TestState.h"
#include "../engine/Tools/Math/Perlin.h"

int main() {
	StateManager minecraft(1280, 720, "Minecraft");
	TestState* introState = new TestState(&minecraft);
	minecraft.pushState(introState);

	while (minecraft.isRunning()) {
		minecraft.handleEvents();
		minecraft.update();
		minecraft.draw();
	}
}