#pragma once
#include <vector>
#include <GL/glew.h>
#include "../../Tools/Math/glm.h"
#include "../../Tools/Texture/Texture.h"

class GuiEntity {

public:
	GuiEntity(std::vector<float>& vertexPositions, glm::vec4 color, Texture* texture);
	~GuiEntity();

	void addData(std::vector<float>& vertexPositions, glm::vec4 color);
	void addVBO(int dimensions, const std::vector<float>& data);
	void deleteData();
	
	inline void bindVAO() { glBindVertexArray(m_vao); };
	inline int getVertexCount() { return m_vertexCount; };
	inline Texture* getTexture() { return m_texture; };
	inline glm::vec4 getColor() { return m_color; };

private:
	unsigned int m_vao;
	int m_vboCount = 0;
	std::vector<unsigned int> m_buffers;
	int m_vertexCount = 4;
	glm::vec4 m_color;
	Texture* m_texture;
};