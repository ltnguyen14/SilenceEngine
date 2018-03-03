#include <math.h>
#include "TestState.h"


TestState::TestState(StateManager* game)
{
	/*game->m_engine.m_renderSystem->addCube({ 0, 0, -5 }, { 1, 1, 1 }, "Grass");
	game->m_engine.m_renderSystem->addCube({ -5, 0, -5 }, { 1, 1, 1 }, "Dirt");
	game->m_engine.m_renderSystem->addCube({ 5, 0, -5 }, { 1, 1, 1 }, "Stone");*/
	
	for (size_t i = 0; i < 17; i+= 17)
	{
		game->m_engine.m_renderSystem->createTerrain(8, { 0, 0, 0 });

	}

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
	game->m_engine.m_renderSystem->renderText({ 0, 0 }, "Minecraft Clone", 100, {0.2f, 0.4f, 0.8f, 1.0f});
	game->m_engine.m_renderSystem->renderChunks(m_camera);
}

