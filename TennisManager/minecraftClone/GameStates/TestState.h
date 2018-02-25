#pragma once
#include "../../engine/GameSkeleton/GameState.h"

class TestState : public GameState{
public:
	TestState(StateManager* game);

	void Init();
	void Cleanup();

	void handleEvents(StateManager* game);
	void update(StateManager* game);
	void draw(StateManager* game);

private:
	Player* m_player;
	Camera* m_camera;
};