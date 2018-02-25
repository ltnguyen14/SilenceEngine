#pragma once
#include "Model.h"
#include "../../Tools/Texture/Texture.h"
#include "../../Tools/Math/glm.h"

class CubeEntity : public Model {
public:
	CubeEntity(const std::vector<float>& vertexPositions,
		const std::vector<unsigned int>&  indices,
		const std::vector<float>&  textureCoords,
		Texture texture);
	~CubeEntity();

	void setPosition(glm::vec3 position) { m_position = position; };
	inline glm::vec3 getPosition() { return m_position; };
	inline Texture getTexture() { return m_texture; };

private:
	glm::vec3 m_position;
	Texture m_texture;
};