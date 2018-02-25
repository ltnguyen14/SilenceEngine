#include "Model.h"

Model::Model(const std::vector<float>& vertexPositions, const std::vector<float>&  textureCoords) {
	addData(vertexPositions, textureCoords);
}

Model::~Model() {
	deleteData();
}

void Model::addData(const std::vector<float>& vertexPositions, const std::vector<float>&  textureCoords)
{
	if (m_vao != 0)
		deleteData();

	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);

	addVBO(3, vertexPositions);
	addVBO(2, textureCoords);
}

void Model::deleteData()
{
	glDeleteVertexArrays(1, &m_vao);
	glDeleteBuffers(m_buffers.size(), m_buffers.data());
	m_buffers.clear();

	m_vboCount = 0;
	m_vao = 0;
}

void Model::addVBO(int dimensions, const std::vector<float>& data)
{
	unsigned int vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), data.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(m_vboCount, dimensions, GL_FLOAT, GL_FALSE, 0, nullptr);
	glEnableVertexAttribArray(m_vboCount++);

	m_buffers.push_back(vbo);
}

void Model::bindVAO() const
{
	glBindVertexArray(m_vao);
}

void Model::unbind() const
{
	glBindVertexArray(0);
}

