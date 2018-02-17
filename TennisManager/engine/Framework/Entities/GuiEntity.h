#pragma once
#include <vector>
#include <GL/glew.h>
#include "../../Tools/Math/glm.h"

class GuiEntity {

public:
	GuiEntity(std::vector<float>& vertexPositions, const std::vector<float>& color);
	~GuiEntity();

	void addData(std::vector<float>& vertexPositions, const std::vector<float>& color);
	void addVBO(int dimensions, const std::vector<float>& data);
	void deleteData();
	
	inline void bindVAO() { glBindVertexArray(m_vao); };
	inline int getVertexCount() { return m_vertexCount; };

private:
	unsigned int m_vao;
	int m_vboCount = 0;
	std::vector<unsigned int> m_buffers;
	int m_vertexCount = 4;
};