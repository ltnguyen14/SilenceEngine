#include <math.h>
#include "TestState.h"


TestState::TestState(StateManager* game)
{
	game->m_engine.m_renderSystem->addCube({ 0, 0, -5 }, { 1, 1, 1 }, "AtlasTest.png");
	m_player = game->m_engine.m_renderSystem->createPlayer();
	m_camera = game->m_engine.m_renderSystem->getCamera();
}

void TestState::Init()
{
}

void TestState::Cleanup()
{
}

void TestState::handleEvents(StateManager * game)
{
	m_player->handleInput();
}

void TestState::update(StateManager * game)
{
	game->m_engine.update();
	m_player->update(1);
	m_camera->update();
}

void TestState::draw(StateManager * game)
{
	game->m_engine.m_renderSystem->renderText({ 0, 0 }, "Test string", 300, {0.2f, 0.4f, 0.8f, 1.0f});
	game->m_engine.m_renderSystem->renderCubes(m_camera);
}

