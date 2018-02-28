#include "ChunkRenderer.h"

ChunkRenderer::ChunkRenderer()
	:CubeRenderer()
{
}

ChunkRenderer::~ChunkRenderer()
{
}

void ChunkRenderer::addChunk(glm::vec3 position, glm::vec3 scale, const std::string & material, ResManager * resManager)
{
	std::vector<float> verts;
	std::vector<float> texCoords;

	for (int x = 0; x < scale.x; x++)
		for (int y = 0; y < scale.y; y++)
			for (int z = 0; z < scale.z; z++) {
				if (z == 0)
					addFace(verts, texCoords, position + glm::vec3(x, y, z), { 0.5f, 0.5f, 0.5f }, material, resManager, BACK);
				if (z == scale.z - 1)
					addFace(verts, texCoords, position + glm::vec3(x, y, z), { 0.5f, 0.5f, 0.5f }, material, resManager, FRONT);
				if (y == 0)
					addFace(verts, texCoords, position + glm::vec3(x, y, z), { 0.5f, 0.5f, 0.5f }, material, resManager, BOTTOM);
				if (y == scale.y - 1)
					addFace(verts, texCoords, position + glm::vec3(x, y, z), { 0.5f, 0.5f, 0.5f }, material, resManager, TOP);
				if (x == 0)
					addFace(verts, texCoords, position + glm::vec3(x, y, z), { 0.5f, 0.5f, 0.5f }, material, resManager, LEFT);
				if (x == scale.x - 1)
					addFace(verts, texCoords, position + glm::vec3(x, y, z), { 0.5f, 0.5f, 0.5f }, material, resManager, RIGHT);
			}
	Texture* texture = resManager->getBlockData(material)->getTexture();
	Chunk * chunk = new Chunk(verts, texCoords, *texture);
	chunk->setPosition(position);
	m_chunks.push_back(chunk);
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
