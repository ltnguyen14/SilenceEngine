#pragma once
#include "../GameState.h"

class IntroState : public GameState{
public:
	IntroState();

	void Init();
	void Cleanup();

	void handleEvents(StateManager* game);
	void update(StateManager* game);
	void draw(StateManager* game);

private:
};