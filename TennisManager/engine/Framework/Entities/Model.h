#pragma once
#include <vector>
#include <GL/glew.h>

class Model {
public:
	Model() = default;
	Model(const std::vector<float>& vertexPositions,
		const std::vector<float>&  textureCoords);
	~Model();

	void addData(const std::vector<float>& vertexPositions,
		const std::vector<float>&  textureCoords);

	void deleteData();

	void bindVAO() const;
	void unbind() const;

protected:
	void addVBO(int dimensions, const std::vector<float>& data);

	unsigned int m_vao = 0;
	int m_vboCount = 0;
	std::vector<unsigned int> m_buffers;
};