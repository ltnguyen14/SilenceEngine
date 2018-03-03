#pragma once
#include "../Renderers/ChunkRenderer.h"

class TerrainGenerator {
public:
	TerrainGenerator(ChunkRenderer* chunkRenderer);
	~TerrainGenerator();

	void createTerrain(unsigned int height, glm::vec3 position, ResManager* resManager);

private:
	ChunkRenderer * m_chunkRenderer;
};