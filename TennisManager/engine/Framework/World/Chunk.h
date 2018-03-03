#pragma once
#include <unordered_map>
#include "../Entities/CubeEntity.h"

class Chunk : public CubeEntity {
public:
	Chunk(const std::vector<float>& vertexPositions,
		const std::vector<float>&  textureCoords,
		Texture& texture);
	~Chunk();

	inline std::vector<glm::vec3>& getBlockPositions() { return m_positions; };
	inline void setBlockPositions(std::vector<glm::vec3> positions) { m_positions = positions; };
	inline std::unordered_map<std::string, std::vector<glm::vec3>>& getBlockInfo() { return m_blocks; };
	inline void setBlockInfo(std::unordered_map<std::string, std::vector<glm::vec3>>& blocks) { m_blocks = blocks; };

private:
	void generateIndicies();
	std::vector<unsigned int> m_indexCollection;
	std::vector<glm::vec3> m_positions;
	std::unordered_map<std::string, std::vector<glm::vec3>> m_blocks;

};