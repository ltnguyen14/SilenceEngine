#include "TerrainGenerator.h"

TerrainGenerator::TerrainGenerator(ChunkRenderer* chunkRenderer)
	:m_chunkRenderer(chunkRenderer)
{
}

TerrainGenerator::~TerrainGenerator()
{
}

void TerrainGenerator::createTerrain(unsigned int height, glm::vec3 position, ResManager* resManager)
{
	if (height < 5) {
		std::cout << "Height too low!" << std::endl;
		return;
	}
	// Create layers
	m_chunkRenderer->addChunk(position, {16, 5, 16}, "Stone", resManager);
	m_chunkRenderer->addChunk(position + glm::vec3(0, 5, 0), { 16, height - 5, 16 }, "Dirt", resManager);
	m_chunkRenderer->addChunk(position + glm::vec3(0, height, 0), { 16, 1, 16 }, "Grass", resManager);

}
