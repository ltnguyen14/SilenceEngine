#include "CubeEntity.h"

CubeEntity::CubeEntity(const std::vector<float>& vertexPositions, 
	const std::vector<unsigned int>&  indices,
	const std::vector<float>& textureCoords, Texture& texture)
	: Model(vertexPositions, indices, textureCoords), m_texture(texture)
{
}

CubeEntity::~CubeEntity()
{
	deleteData();
}
