#include "ChunkRenderer.h"

ChunkRenderer::ChunkRenderer()
	:CubeRenderer()
{
}

ChunkRenderer::~ChunkRenderer()
{
}

void ChunkRenderer::addChunk(glm::vec3 position, glm::vec3 scale, const std::string & material, ResManager * resManager)
{
	addCube(position, scale, material, resManager);
}

void ChunkRenderer::renderChunks(Window * window, Camera * camera)
{
	renderCubes(window, camera);
}
