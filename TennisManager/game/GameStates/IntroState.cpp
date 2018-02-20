#include "IntroState.h"

IntroState::IntroState()
	:m_userPaddle({ -0.9f, 0.0f }, { 0.2f, 0.4f, 0.8f, 1.0f }, {0.05f, 0.3f}, "gray_bg.png"),
		m_ball({ 0.0f, 0.0f }, { 0.2f, 0.4f, 0.8f, 1.0f }, { 0.02f, 0.02f }, "gray_bg.png")
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
	if (game->m_engine.m_inputSystem->keyPressed(GLFW_KEY_W))
		if (m_userPaddle.getPositions().y + m_userPaddle.getDimensions().y / 2 < 1)
			m_userPaddle.setPosition({ m_userPaddle.getPositions().x, m_userPaddle.getPositions().y + 0.05 });
	if (game->m_engine.m_inputSystem->keyPressed(GLFW_KEY_S))
		if (m_userPaddle.getPositions().y - m_userPaddle.getDimensions().y / 2 > -1)
			m_userPaddle.setPosition({ m_userPaddle.getPositions().x, m_userPaddle.getPositions().y - 0.05 });
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
