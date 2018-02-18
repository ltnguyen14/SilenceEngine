#include "GuiEntity.h"

GuiEntity::GuiEntity(std::vector<float>& vertexPositions, glm::vec4 color, Texture* texture)
	:m_texture(texture)
{
	addData(vertexPositions, color);
}

GuiEntity::~GuiEntity()
{
	deleteData();
}

void GuiEntity::addData(std::vector<float>& vertexPositions, glm::vec4 color)
{
	if (m_vao != 0)
		deleteData();
	
	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);

	std::vector<float> textureCoords = {
		0, 0,
		0, 1,
		1, 0,
		1, 1,
	};

	m_color = color;
	addVBO(2, vertexPositions);
	addVBO(2, textureCoords);
}

void GuiEntity::addVBO(int dimensions, const std::vector<float>& data)
{
	unsigned int vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), data.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(m_vboCount, dimensions, GL_FLOAT, GL_FALSE, 0, nullptr);
	glEnableVertexAttribArray(m_vboCount++);
	m_buffers.push_back(vbo);
}

void GuiEntity::deleteData()
{
	glDeleteVertexArrays(1, &m_vao);
	glDeleteBuffers(m_buffers.size(), m_buffers.data());

	m_vao = 0;
	m_vboCount = 0;
	m_buffers.clear();
}
