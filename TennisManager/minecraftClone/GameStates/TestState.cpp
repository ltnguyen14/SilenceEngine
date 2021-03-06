#include <math.h>
#include "TestState.h"


TestState::TestState(StateManager* game)
{
	/*game->m_engine.m_renderSystem->addCube({ 0, 0, -5 }, { 1, 1, 1 }, "Grass");
	game->m_engine.m_renderSystem->addCube({ -5, 0, -5 }, { 1, 1, 1 }, "Dirt");
	game->m_engine.m_renderSystem->addCube({ 5, 0, -5 }, { 1, 1, 1 }, "Stone");*/
	
	for (size_t x = 0; x < 16; x += 16)
		for (size_t z = 0; z < 16; z += 16)
		{
			game->m_engine.m_renderSystem->createTerrain(8, { x, 0, z });
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

