#pragma once
#include "StateManager.h"

class GameState {
public:
	GameState() {};

	virtual void Init() = 0;
	virtual void Cleanup() = 0;

	virtual void handleEvents(StateManager* game) = 0;
	virtual void update(StateManager* game) = 0;
	virtual void draw(StateManager* game) = 0;

	void changeState(StateManager* game, GameState* state) {
		game->changeState(state);
	}

private:
};