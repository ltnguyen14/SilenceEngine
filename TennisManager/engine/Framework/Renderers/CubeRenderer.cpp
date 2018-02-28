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

		// Top
		-scale.x, scale.y, scale.z,
		scale.x, scale.y, scale.z,
		scale.x, scale.y, -scale.z,
		-scale.x, scale.y, -scale.z,

		// Bottom
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
	Texture* texture = resManager->getBlockData(material)->getTexture();
	
	CubeEntity * cube = new CubeEntity(vertexPositions, indicies, texCoords, *texture);
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

void CubeRenderer::addFace(std::vector<float>& verts, std::vector<float>& textureCoords, glm::vec3 position, glm::vec3 scale, const std::string & material, ResManager * resManager, Side side)
{
	std::vector<float> vertexPositions;
	std::vector<float> texCoords;

	if (side == FRONT) {
		vertexPositions = {
			// Front
			-scale.x, -scale.y, scale.z,
			scale.x, -scale.y, scale.z,
			scale.x, scale.y, scale.z,
			-scale.x, scale.y, scale.z,
		};
		texCoords = resManager->getBlockData(material)->getTexSide();
	}
	else if (side == RIGHT) {
		vertexPositions = {
			// Right
			scale.x, -scale.y, scale.z,
			scale.x, -scale.y, -scale.z,
			scale.x, scale.y, -scale.z,
			scale.x, scale.y, scale.z,
		};
		texCoords = resManager->getBlockData(material)->getTexSide();
	}
	else if (side == BACK) {
		vertexPositions = {
			// Back
			-scale.x, -scale.y, -scale.z,
			scale.x, -scale.y, -scale.z,
			scale.x, scale.y, -scale.z,
			-scale.x, scale.y, -scale.z,
		};
		texCoords = resManager->getBlockData(material)->getTexSide();
	}
	else if (side == LEFT) {
		vertexPositions = {
			// Left
			-scale.x, -scale.y, scale.z,
			-scale.x, -scale.y, -scale.z,
			-scale.x, scale.y, -scale.z,
			-scale.x, scale.y, scale.z,
		};
		texCoords = resManager->getBlockData(material)->getTexSide();
	}
	else if (side == TOP) {
		vertexPositions = {
			// Top
			-scale.x, scale.y, scale.z,
			scale.x, scale.y, scale.z,
			scale.x, scale.y, -scale.z,
			-scale.x, scale.y, -scale.z,
		};
		texCoords = resManager->getBlockData(material)->getTexTop();
	}
	else if (side == BOTTOM) {
		vertexPositions = {
			// Bottom
			scale.x, -scale.y, -scale.z,
			-scale.x, -scale.y, -scale.z,
			-scale.x, -scale.y, scale.z,
			scale.x, -scale.y, scale.z,
		};
		texCoords = resManager->getBlockData(material)->getTexBottom();
	}

	std::vector<float> positionOffset;
	for (size_t i = 0; i < 4; i++)
	{
		positionOffset.insert(positionOffset.end(), { position.x, position.y, position.z });
	};
	
	for (size_t i = 0; i < vertexPositions.size(); i++)
	{
		vertexPositions[i] += positionOffset[i];
	}

	verts.insert(verts.end(), vertexPositions.begin(), vertexPositions.end());
	textureCoords.insert(textureCoords.end(), texCoords.begin(), texCoords.end());

}
