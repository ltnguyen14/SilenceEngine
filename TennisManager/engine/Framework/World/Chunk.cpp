#include "Chunk.h"

Chunk::Chunk(const std::vector<float>& vertexPositions,
	const std::vector<float>&  textureCoords,
	Texture& texture)
	: CubeEntity(vertexPositions, {}, textureCoords, texture)
{
	generateIndicies();
}

Chunk::~Chunk()
{
}

void Chunk::generateIndicies()
{
	for (unsigned int i = 0; i < m_vertCount; i++) {
		std::vector<unsigned int> indicies = {
			i * 4, i * 4 + 1, i * 4 + 2,
			i * 4 + 2, i * 4 + 3, i * 4,
		};
		m_indexCollection.insert(m_indexCollection.begin(), indicies.begin(), indicies.end());
		m_indicesCount += 6;
	}

	addEBO(m_indexCollection);
}
