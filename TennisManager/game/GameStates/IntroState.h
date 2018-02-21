#pragma once
#include "../GameState.h"
#include "../GameComponents/Paddle.h"

class IntroState : public GameState{
public:
	IntroState(StateManager* game);

	void Init();
	void Cleanup();

	void handleEvents(StateManager* game);
	void update(StateManager* game);
	void draw(StateManager* game);

private:
	void drawObj(StateManager * game, Paddle paddle);
	bool checkCollision(Paddle object_1, Paddle object_2);
	Paddle m_userPaddle, m_ball;
};