#pragma once
#include <unordered_map>
#include "../../Tools/Shader/Shader.h"
#include "../Entities/Camera.h"
#include "../Entities/CubeEntity.h"
#include "../../ResManager/ResManager.h"
#include "CubeRenderer.h"

class ChunkRenderer : public CubeRenderer{
public:
	ChunkRenderer();
	~ChunkRenderer();

	void addChunk(glm::vec3 position, glm::vec3 scale, const std::string& material, ResManager* resManager, bool TERRAIN_GEN = false);
	void renderChunks(Window* window, Camera* camera);

private:
	std::vector<Chunk*> m_chunks;
};