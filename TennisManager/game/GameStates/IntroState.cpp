#include "IntroState.h"
#define USER_SPEED 5.0f
#define BALL_SPEED 7.0f

IntroState::IntroState(StateManager* game)
	:m_userPaddle({ game->m_width/32, game->m_height/2 }, { 0.2f, 0.4f, 0.8f, 1.0f }, { game->m_width/64, game->m_height/8 }, "gray_bg.png"),
		m_ball({ game->m_width/2, game->m_height/2 }, { 1.0f, 0.4f, 0.8f, 1.0f }, { game->m_width/128, game->m_width/128 }, "gray_bg.png")
{
	
}

void IntroState::Init()
{
}

void IntroState::Cleanup()
{
}

void IntroState::handleEvents(StateManager * game)
{
	// Handle movement for user paddle
	if (game->m_engine.m_inputSystem->keyPressed(GLFW_KEY_W))
		if (m_userPaddle.getPositions().y + m_userPaddle.getDimensions().y / 2 + USER_SPEED < game->m_height)
			m_userPaddle.moveUp(USER_SPEED);
	if (game->m_engine.m_inputSystem->keyPressed(GLFW_KEY_S))
		if (m_userPaddle.getPositions().y - m_userPaddle.getDimensions().y / 2 - USER_SPEED > 0)
			m_userPaddle.moveUp(-USER_SPEED);
}

void IntroState::update(StateManager * game)
{
	game->m_engine.update();
}

void IntroState::draw(StateManager * game)
{
	drawObj(game, m_userPaddle);
	drawObj(game, m_ball);
}

void IntroState::drawObj(StateManager * game, Paddle paddle)
{
	game->m_engine.m_renderSystem->drawQuad(paddle.getPositions(), paddle.getDimensions().x,
											paddle.getDimensions().y, paddle.getColor(),
											paddle.getTexture());
}

bool IntroState::checkCollision(Paddle object_1, Paddle object_2)
{
	return false;
}
