#include "IntroState.h"

IntroState::IntroState()
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
	if (game->m_engine.m_inputSystem->keyPressed(GLFW_KEY_A))
		std::cout << "A pressed" << std::endl;
}

void IntroState::update(StateManager * game)
{
	game->m_engine.update();
}

void IntroState::draw(StateManager * game)
{
	game->m_engine.m_renderSystem->drawQuad({ 0, 0 }, 0.2f, 0.5f, { 0.2f, 0.4f, 0.8f, 1.0f }, "arrow-right.png");
}
