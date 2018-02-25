#pragma once
#include "Model.h"
#include "../../Tools/Texture/Texture.h"

class CubeEntity : public Model {
public:
	CubeEntity(const std::vector<float>& vertexPositions,
		const std::vector<float>&  textureCoords,
		Texture texture);
	~CubeEntity();

	void setPosition(glm::vec3 position) { m_position = position; };

private:
	glm::vec3 m_position;
	Texture m_texture;
};