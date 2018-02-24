#pragma once
#include <vector>
#include "MetaFile.h"
#include "../../Tools/Math/glm.h"

class TextObj {
public:
	TextObj();
	~TextObj();

	void AddData(std::string text, glm::vec2 position, float width, glm::vec4 color, bool CENTER_FLAG, MetaFile& metaFile);
	void bindVAO() const;

	inline glm::vec2 getPosition() const { return m_position; };
	inline glm::vec4 getColor() const { return m_color; };
	inline unsigned int getVertCount() const { return m_vertCount; };


private:
	void deleteData();
	void addVBO(int dimensions, const std::vector<float>& data);

private:
	glm::vec2 m_cursor;
	glm::vec2 m_position;
	glm::vec4 m_color;
	unsigned int m_vertCount;

	unsigned int m_vao = 0;
	int m_vboCount = 0;
	std::vector<unsigned int> m_buffers;
};