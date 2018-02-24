#include <math.h>
#include "IntroState.h"
#define USER_SPEED 8.0f
#define BALL_SPEED 10.0f

IntroState::IntroState(StateManager* game)
	:m_userPaddle({ game->m_width/32, game->m_height/2 }, { 0.2f, 0.4f, 0.8f, 1.0f }, { game->m_width/64, game->m_height/8 }, "gray_bg.png"),
	m_oppPaddle({ game->m_width - game->m_width/32, game->m_height/2 }, { 1.0f, 0.4f, 0.0f, 1.0f }, { game->m_width/64, game->m_height/8 }, "gray_bg.png"),
	m_ball({ game->m_width / 2, game->m_height / 2 }, { 1.0f, 0.4f, 0.8f, 1.0f }, { game->m_width / 128, game->m_width / 128 }, "gray_bg.png", { -BALL_SPEED, 0 })
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
	if (game->m_engine.m_inputSystem->keyPressed(GLFW_KEY_S))
		if (m_userPaddle.getPositions().y + m_userPaddle.getDimensions().y / 2 + USER_SPEED < game->m_height)
			m_userPaddle.moveUp(USER_SPEED);
	if (game->m_engine.m_inputSystem->keyPressed(GLFW_KEY_W))
		if (m_userPaddle.getPositions().y - m_userPaddle.getDimensions().y / 2 - USER_SPEED > 0)
			m_userPaddle.moveUp(-USER_SPEED);

	// Wall
	if (m_ball.getPositions().y > game->m_height)
		m_ball.setVelocity({ m_ball.getVelocity().x, -BALL_SPEED });

	if (m_ball.getPositions().y < 0)
		m_ball.setVelocity({ m_ball.getVelocity().x, BALL_SPEED });

	// Collision between user paddle and ball
	if (checkCollision(m_userPaddle, m_ball)) {
		float distance = m_ball.getPositions().y - m_userPaddle.getPositions().y;
		if (distance < 0)
			m_ball.setVelocity({ BALL_SPEED * (1 + std::abs(distance) / m_userPaddle.getDimensions().y), -BALL_SPEED });
		else
			m_ball.setVelocity({ BALL_SPEED * (1 + std::abs(distance) / m_userPaddle.getDimensions().y), BALL_SPEED });
	}

	// Collision between opponent paddle and ball
	if (checkCollision(m_oppPaddle, m_ball))
		if (m_ball.getPositions().y < m_oppPaddle.getPositions().y)
			m_ball.setVelocity({ -BALL_SPEED, -BALL_SPEED });
		else
			m_ball.setVelocity({ -BALL_SPEED, BALL_SPEED });

	// Handle movement for opponent paddle and ball
	if (m_oppPaddle.getPositions().y < m_ball.getPositions().y)
		m_oppPaddle.setVelocity({ 0, USER_SPEED });

	if (m_oppPaddle.getPositions().y > m_ball.getPositions().y)
		m_oppPaddle.setVelocity({ 0, -USER_SPEED });

	m_oppPaddle.move(m_oppPaddle.getVelocity());
	m_ball.move(m_ball.getVelocity());

	// Reset game
	if (m_ball.getPositions().x < -10 || m_ball.getPositions().x > game->m_width) {
		m_ball.setPosition({ game->m_width / 2, game->m_height / 2 });
		m_ball.setVelocity({ -BALL_SPEED, 0 });

		m_userPaddle.setPosition({ game->m_width / 32, game->m_height / 2 });

		m_oppPaddle.setPosition({ game->m_width - game->m_width / 32, game->m_height / 2 });
		m_oppPaddle.setVelocity({ 0, 0 });
	}
}

void IntroState::update(StateManager * game)
{
	game->m_engine.update();
}

void IntroState::draw(StateManager * game)
{
	drawObj(game, m_ball);
	drawObj(game, m_userPaddle);
	drawObj(game, m_oppPaddle);

	game->m_engine.m_renderSystem->renderText({ game->m_width/2, 0 }, "Hello World", 200, {0.4f, 0.2f, 0.6f, 1.0f});
}

void IntroState::drawObj(StateManager * game, Paddle paddle)
{
	game->m_engine.m_renderSystem->drawQuad(paddle.getPositions(), paddle.getDimensions().x,
											paddle.getDimensions().y, paddle.getColor(),
											paddle.getTexture());
}

bool IntroState::checkCollision(Paddle object_1, Paddle object_2)
{
	//Width
	if (std::abs(object_1.getPositions().x - object_2.getPositions().x) < std::max(object_1.getDimensions().x, object_2.getDimensions().x))
		//Height
		if (std::abs(object_1.getPositions().y - object_2.getPositions().y) < std::max(object_1.getDimensions().y, object_2.getDimensions().y))
			return true;
	return false;
}
