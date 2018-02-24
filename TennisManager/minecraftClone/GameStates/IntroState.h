#pragma once
#include "../../engine/GameSkeleton/GameState.h"

class IntroState : public GameState{
public:
	IntroState(StateManager* game);

	void Init();
	void Cleanup();

	void handleEvents(StateManager* game);
	void update(StateManager* game);
	void draw(StateManager* game);

private:

};