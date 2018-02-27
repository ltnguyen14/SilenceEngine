#pragma once
#include <vector>
#include "../../Tools/Shader/Shader.h"
#include "../Entities/CubeEntity.h"
#include "../../ResManager/ResManager.h"

class CubeRenderer {
public:
	CubeRenderer();
	~CubeRenderer();

	void addCube(glm::vec3 position, glm::vec3 scale, const std::string& material, ResManager* resManager);
	void renderCubes(Window* window, Camera* camera);

private:
	Shader m_shader;
	std::vector<CubeEntity*> m_cubes;
};