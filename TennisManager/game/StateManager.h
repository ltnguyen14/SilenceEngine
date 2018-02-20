#pragma once
#include "../engine/SilenceEngine.h"
#include <queue>

class GameState;

class StateManager {
public:
	StateManager(int width, int height, std::string title);
	void cleanup();

	void changeState(GameState* state);
	void pushState(GameState* state);
	void popState(GameState* state);

	void handleEvents();
	void update();
	void draw();

	bool isRunning() {
		return m_engine.isRunning();
	}

	SilenceEngine m_engine;

private:
	std::queue<GameState*> m_states;
};