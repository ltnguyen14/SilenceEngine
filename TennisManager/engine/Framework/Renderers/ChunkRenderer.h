#pragma once
#include "../../Tools/Shader/Shader.h"
#include "../Entities/CubeEntity.h"
#include "../../ResManager/ResManager.h"
#include "CubeRenderer.h"

class ChunkRenderer : public CubeRenderer{
public:
	ChunkRenderer();
	~ChunkRenderer();

	void addChunk(glm::vec3 position, glm::vec3 scale, const std::string& material, ResManager* resManager);
	void renderChunks(Window* window, Camera* camera);

private:

};