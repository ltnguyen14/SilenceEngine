#include "../../Tools/Math/Perlin.h"
#include "ChunkRenderer.h"

ChunkRenderer::ChunkRenderer()
	:CubeRenderer()
{
}

ChunkRenderer::~ChunkRenderer()
{
}

void ChunkRenderer::addChunk(glm::vec3 position, glm::vec3 scale, const std::string & material, ResManager * resManager, bool TERRAIN_GEN)
{
	std::vector<float> verts;
	std::vector<float> texCoords;
	std::vector<glm::vec3> m_positions;

	std::unordered_map<std::string, std::vector<glm::vec3>> m_blocks;
	srand(1);
	PerlinNoise perlin(1.0, 1.0, 6.0, 2.0, rand());

	for (int x = 0; x < scale.x; x++)
		for (int z = 0; z < scale.z; z++) {
			if (!TERRAIN_GEN) {
				for (int y = 0; y < scale.y; y++)
				{
					if (m_blocks.find(material) != m_blocks.end()) {
						m_blocks[material].push_back(glm::vec3(x, y, z));
					}
					else {
						m_blocks[material] = std::vector<glm::vec3>();
						m_blocks[material].push_back(glm::vec3(x, y, z));
					}
					m_positions.push_back(glm::vec3(x, y, z));
				}
			}
			else {
				int lastPos;
				for (int y = 0; y < perlin.GetHeight(x, z) + 6; y++) {
					if (m_blocks.find(material) != m_blocks.end()) {
						m_blocks[material].push_back(glm::vec3(x, y, z));
					}
					else {
						m_blocks[material] = std::vector<glm::vec3>();
						m_blocks[material].push_back(glm::vec3(x, y, z));
					}
					lastPos = y;
					m_positions.push_back(glm::vec3(x, y, z));
				}
			}
		}
	for (auto& blockType : m_blocks) {
		if (blockType.first != "Air")
			for (auto& block_position : blockType.second) {
				auto airBlocks = m_blocks["Air"];
				// If next to air block or nothing
				if (std::find(airBlocks.begin(), airBlocks.end(), glm::vec3(block_position.x + 1, block_position.y, block_position.z)) != airBlocks.end()
					|| std::find(m_positions.begin(), m_positions.end(), glm::vec3(block_position.x + 1, block_position.y, block_position.z)) == m_positions.end()
					) {
					addFace(verts, texCoords, position + block_position, { 0.5f, 0.5f, 0.5f }, material, resManager, RIGHT);
				}

				if (std::find(airBlocks.begin(), airBlocks.end(), glm::vec3(block_position.x - 1, block_position.y, block_position.z)) != airBlocks.end()
					|| std::find(m_positions.begin(), m_positions.end(), glm::vec3(block_position.x - 1, block_position.y, block_position.z)) == m_positions.end()
					) {
					addFace(verts, texCoords, position + block_position, { 0.5f, 0.5f, 0.5f }, material, resManager, LEFT);
				}

				if (std::find(airBlocks.begin(), airBlocks.end(), glm::vec3(block_position.x, block_position.y + 1, block_position.z)) != airBlocks.end()
					|| std::find(m_positions.begin(), m_positions.end(), glm::vec3(block_position.x, block_position.y + 1, block_position.z)) == m_positions.end()
					) {
					addFace(verts, texCoords, position + block_position, { 0.5f, 0.5f, 0.5f }, material, resManager, TOP);
				}

				if (std::find(airBlocks.begin(), airBlocks.end(), glm::vec3(block_position.x, block_position.y - 1, block_position.z)) != airBlocks.end()
					|| std::find(m_positions.begin(), m_positions.end(), glm::vec3(block_position.x, block_position.y - 1, block_position.z)) == m_positions.end()
					) {
					addFace(verts, texCoords, position + block_position, { 0.5f, 0.5f, 0.5f }, material, resManager, BOTTOM);
				}

				if (std::find(airBlocks.begin(), airBlocks.end(), glm::vec3(block_position.x, block_position.y, block_position.z + 1)) != airBlocks.end()
					|| std::find(m_positions.begin(), m_positions.end(), glm::vec3(block_position.x, block_position.y, block_position.z + 1)) == m_positions.end()
					) {
					addFace(verts, texCoords, position + block_position, { 0.5f, 0.5f, 0.5f }, material, resManager, FRONT);
				}
				
				if (std::find(airBlocks.begin(), airBlocks.end(), glm::vec3(block_position.x, block_position.y, block_position.z - 1)) != airBlocks.end()
					|| std::find(m_positions.begin(), m_positions.end(), glm::vec3(block_position.x, block_position.y, block_position.z - 1)) == m_positions.end()
					) {
					addFace(verts, texCoords, position + block_position, { 0.5f, 0.5f, 0.5f }, material, resManager, BACK);
				}
			}
	}

	Texture* texture = resManager->getBlockData(material)->getTexture();
	Chunk * chunk = new Chunk(verts, texCoords, *texture);
	chunk->setBlockPositions(m_positions);
	chunk->setBlockInfo(m_blocks);
	m_chunks.push_back(chunk);
	std::cout << "Chunk added!" << std::endl;
}

void ChunkRenderer::renderChunks(Window * window, Camera * camera)
{
	m_shader.Bind();
	m_shader.SetUniformMat4("projViewMatrix", camera->getProjectionViewMatrix());

	for (auto& chunk : m_chunks)
	{
		chunk->bindVAO();
		chunk->getTexture()->Bind(0);
		m_shader.SetUniformMat4("modelMatrix", makeModelMatrix(chunk->getPosition(), { 0, 0, 0 }));
		glDrawElements(GL_TRIANGLES, chunk->getIndicesCount(), GL_UNSIGNED_INT, nullptr);
	}
}
