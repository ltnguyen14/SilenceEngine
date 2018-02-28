#pragma once
#include "../Entities/CubeEntity.h"

class Chunk : public CubeEntity {
public:
	Chunk(const std::vector<float>& vertexPositions,
		const std::vector<float>&  textureCoords,
		Texture& texture);
	~Chunk();

private:
	void generateIndicies();
	std::vector<unsigned int> m_indexCollection;
};