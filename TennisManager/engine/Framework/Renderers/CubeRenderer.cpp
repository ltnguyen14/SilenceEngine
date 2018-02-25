#include "CubeRenderer.h"

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
			scale.x,  scale.y, scale.z,
			scale.x, -scale.y, scale.z,
			-scale.x, -scale.y, scale.z,

			-scale.x,  scale.y, -scale.z,
			scale.x,  scale.y, -scale.z,
			scale.x, -scale.y, -scale.z,
			-scale.x, -scale.y, -scale.z,
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

void CubeRenderer::renderCubes(Window * window)
{
	m_shader.Bind();
	m_shader.SetUniformMat4("projViewMatrix", camera.getProjectionViewMatrix());
	m_texture.Bind(0);

	for (auto& quad : m_quads)
	{
		std::get<0>(quad)->bindVAO();
		m_shader.SetUniformMat4("modelMatrix", makeModelMatrix({ std::get<1>(quad),{ 0, 0, 0 } }));
		GLCALL(glDrawElements(GL_TRIANGLES, std::get<0>(quad)->getIndicesCount(), GL_UNSIGNED_INT, nullptr));
	}
	for (auto& quad : m_quads)
		delete(std::get<0>(quad));

	m_quads.clear();
}
