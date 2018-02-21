#include "StateManager.h"
#include "GameState.h"


StateManager::StateManager(int width, int height, std::string title)
	:m_engine(width, height, title), m_width(width), m_height(height)
{
}

void StateManager::cleanup()
{
}

void StateManager::changeState(GameState * state)
{
	m_states.pop();
	m_states.push(state);
}

void StateManager::pushState(GameState * state)
{
	m_states.push(state);
}

void StateManager::popState()
{
	m_states.pop();
}

void StateManager::handleEvents()
{
	m_states.front()->handleEvents(this);
}

void StateManager::update()
{
	m_states.front()->update(this);
}

void StateManager::draw()
{
	m_states.front()->draw(this);
}
