#include <math.h>
#include "IntroState.h"


IntroState::IntroState(StateManager* game)
{
	game->m_engine.m_renderSystem->addCube({ 500, 500, -120 }, {100, 100, 100}, "Test.png");
}

void IntroState::Init()
{
}

void IntroState::Cleanup()
{
}

void IntroState::handleEvents(StateManager * game)
{
}

void IntroState::update(StateManager * game)
{
	game->m_engine.update();
}

void IntroState::draw(StateManager * game)
{
	game->m_engine.m_renderSystem->renderCubes();
}

