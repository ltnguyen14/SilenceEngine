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

void CubeRenderer::addCube(glm::vec3 position, glm::vec3 scale, const std::string& texture)
{
	CubeEntity * cube = new CubeEntity(
		{
			-scale.x,  scale.y, scale.z,
			scale.x,   scale.y, scale.z,
			scale.x,  -scale.y, scale.z,
			-scale.x, -scale.y, scale.z,

			-scale.x,  scale.y, -scale.z,
			scale.x,   scale.y, -scale.z,
			scale.x,  -scale.y, -scale.z,
			-scale.x, -scale.y, -scale.z,
		},
		{
			// Front
			0, 1, 2,
			2, 3, 0,

			// Back
			4, 5, 6,
			6, 7, 4,

			// Left
			0, 1, 5,
			5, 4, 0,

			// Right
			3, 2, 6,
			6, 7, 3,

			// Top
			0, 4, 7,
			7, 3, 0,

			// Bottom
			1, 2, 6,
			6, 5, 1
		},
		{
			0, 1,
			1, 1,
			1, 0,
			0, 0,

			0, 1,
			1, 1,
			1, 0,
			0, 0,
		},
		texture
	);
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
