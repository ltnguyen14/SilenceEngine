#include "CubeRenderer.h"
#include "../Entities/Camera.h"

CubeRenderer::CubeRenderer()
	:m_shader("res/shaders/basic.shader")
{
}

CubeRenderer::~CubeRenderer()
{
	for (auto& cube : m_cubes)
		delete(&cube);
}

void CubeRenderer::addCube(glm::vec3 position, glm::vec3 scale, const std::string& material, ResManager* resManager)
{
	std::vector<float> vertexPositions =
	{
		// Front
		-scale.x, -scale.y, scale.z,
		scale.x, -scale.y, scale.z,
		scale.x, scale.y, scale.z,
		-scale.x, scale.y, scale.z,

		// Right
		scale.x, -scale.y, scale.z,
		scale.x, -scale.y, -scale.z,
		scale.x, scale.y, -scale.z,
		scale.x, scale.y, scale.z,

		// Back
		-scale.x, -scale.y, -scale.z,
		scale.x, -scale.y, -scale.z,
		scale.x, scale.y, -scale.z,
		-scale.x, scale.y, -scale.z,

		// Left
		-scale.x, -scale.y, scale.z,
		-scale.x, -scale.y, -scale.z,
		-scale.x, scale.y, -scale.z,
		-scale.x, scale.y, scale.z,

		// Up
		-scale.x, scale.y, scale.z,
		scale.x, scale.y, scale.z,
		scale.x, scale.y, -scale.z,
		-scale.x, scale.y, -scale.z,

		// Down
		scale.x, -scale.y, -scale.z,
		-scale.x, -scale.y, -scale.z,
		-scale.x, -scale.y, scale.z,
		scale.x, -scale.y, scale.z,

	};

	std::vector<unsigned int> indicies =
	{
		// Front
		0, 1, 2,
		2, 3, 0,

		// Right
		4, 5, 6,
		6, 7, 4,

		// Back
		8, 9, 10,
		10, 11, 8,

		// Left
		12, 13, 14,
		14, 15, 12,

		// Up
		16, 17, 18,
		18, 19, 16,

		// Down
		20, 21, 22,
		22, 23, 20,
	};

	std::vector<float> texCoords = resManager->getBlockData(material)->getTexCoords();
	std::string texPath = resManager->getBlockData(material)->getTexPath();
	
	CubeEntity * cube = new CubeEntity(vertexPositions, indicies, texCoords, texPath);
	cube->setPosition(position);
	m_cubes.push_back(cube);
}

void CubeRenderer::renderCubes(Window * window, Camera* camera)
{
	m_shader.Bind();
	m_shader.SetUniformMat4("projViewMatrix", camera->getProjectionViewMatrix());


	for (auto& cube : m_cubes)
	{
		cube->bindVAO();
		cube->getTexture()->Bind(0);
		m_shader.SetUniformMat4("modelMatrix", makeModelMatrix(cube->getPosition(), { 0, 0, 0 }));
		glDrawElements(GL_TRIANGLES, cube->getIndicesCount(), GL_UNSIGNED_INT, nullptr);
	}
}
