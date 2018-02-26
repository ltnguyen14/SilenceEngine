#pragma once
#include <vector>
#include <GL/glew.h>

class Model {
public:
	Model() = default;
	Model(const std::vector<float>& vertexPositions,
		const std::vector<unsigned int>&  indices,
		const std::vector<float>&  textureCoords);
	~Model();

	void addData(const std::vector<float>& vertexPositions,
		const std::vector<unsigned int>&  indices,
		const std::vector<float>&  textureCoords);

	void deleteData();

	void bindVAO() const;
	void unbind() const;

	int getIndicesCount() const;
	inline int getVertCount() const { return m_vertCount; };

protected:
	void addVBO(int dimensions, const std::vector<float>& data);
	void addEBO(const std::vector<unsigned int>& indices);

	unsigned int m_vao = 0;
	int m_vboCount = 0;
	int m_indicesCount = 0;
	int m_vertCount = 0;

	std::vector<unsigned int> m_buffers;
	std::vector<unsigned int> m_indexes;
};