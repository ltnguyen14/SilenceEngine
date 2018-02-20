#pragma once
#include "../GameState.h"
#include "../GameComponents/Paddle.h"

class IntroState : public GameState{
public:
	IntroState();

	void Init();
	void Cleanup();

	void handleEvents(StateManager* game);
	void update(StateManager* game);
	void draw(StateManager* game);

private:
	void drawObj(StateManager * game, Paddle paddle);
	Paddle m_userPaddle, m_ball;
};