#pragma once
#include <vector>
#include "../../Tools/Shader/Shader.h"
#include "../Entities/CubeEntity.h"
#include "../World/Chunk.h"
#include "../../ResManager/ResManager.h"

enum Side {
	FRONT, RIGHT, BACK, LEFT, TOP, BOTTOM
};

class CubeRenderer {
public:
	CubeRenderer();
	~CubeRenderer();

	void addCube(glm::vec3 position, glm::vec3 scale, const std::string& material, ResManager* resManager);
	void renderCubes(Window* window, Camera* camera);
	void addFace(std::vector<float>& verts, std::vector<float>& textureCoords, glm::vec3 position, glm::vec3 scale, const std::string& material, ResManager* resManager, Side side);

protected:
	Shader m_shader;
	std::vector<CubeEntity*> m_cubes;
};