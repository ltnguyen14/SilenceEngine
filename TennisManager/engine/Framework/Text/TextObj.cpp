#include "TextObj.h"

TextObj::TextObj()
{
}

TextObj::~TextObj()
{
	deleteData();
}

void TextObj::AddData(std::string text, glm::vec2 position, float width, glm::vec4 color, MetaFile & metaFile)
{
	if (m_vao != 0)
		deleteData();

	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);

	m_position = position;
	m_color = color;
	m_cursor.x = 0;
	std::vector<float> Verts;
	std::vector<float> textureCoords;

	// Find scaling factor for the text
	float totalLength = 0;
	for (unsigned int i = 0; i < text.size(); i++) {
		unsigned short Width = metaFile.m_infoData.Chars[text[i]].Width;
		float OffsetX = metaFile.m_infoData.Chars[text[i]].XOffset;
		totalLength += Width + OffsetX;
	}
	float scale = width / totalLength;

	// Pushing vert and texture
	for (unsigned int i = 0; i < text.size(); i++) {
		unsigned short CharX = metaFile.m_infoData.Chars[text[i]].x;
		unsigned short CharY = metaFile.m_infoData.Chars[text[i]].y;
		unsigned short Width = metaFile.m_infoData.Chars[text[i]].Width;
		unsigned short Height = metaFile.m_infoData.Chars[text[i]].Height;
		float OffsetX = metaFile.m_infoData.Chars[text[i]].XOffset;
		float OffsetY = metaFile.m_infoData.Chars[text[i]].YOffset;

		//upper left
		textureCoords.push_back((float)CharX / (float)metaFile.m_infoData.Width);
		textureCoords.push_back((float)CharY / (float)metaFile.m_infoData.Height);
		Verts.push_back((float)m_cursor.x + OffsetX);
		Verts.push_back((float)OffsetY);

		//lower left
		textureCoords.push_back((float)CharX / (float)metaFile.m_infoData.Width);
		textureCoords.push_back((float)(CharY + Height) / (float)metaFile.m_infoData.Height);
		Verts.push_back((float)m_cursor.x + OffsetX);
		Verts.push_back((float)OffsetY + Height);

		//upper right
		textureCoords.push_back((float)(CharX + Width) / (float)metaFile.m_infoData.Width);
		textureCoords.push_back((float)CharY / (float)metaFile.m_infoData.Height);
		Verts.push_back((float)m_cursor.x + OffsetX + Width);
		Verts.push_back((float)OffsetY);

		//lower left
		textureCoords.push_back((float)CharX / (float)metaFile.m_infoData.Width);
		textureCoords.push_back((float)(CharY + Height) / (float)metaFile.m_infoData.Height);
		Verts.push_back((float)m_cursor.x + OffsetX);
		Verts.push_back((float)OffsetY + Height);

		//upper right
		textureCoords.push_back((float)(CharX + Width) / (float)metaFile.m_infoData.Width);
		textureCoords.push_back((float)CharY / (float)metaFile.m_infoData.Height);
		Verts.push_back((float)m_cursor.x + OffsetX + Width);
		Verts.push_back((float)OffsetY);

		//lower right
		textureCoords.push_back((float)(CharX + Width) / (float)metaFile.m_infoData.Width);
		textureCoords.push_back((float)(CharY + Height) / (float)metaFile.m_infoData.Height);
		Verts.push_back((float)m_cursor.x + OffsetX + Width);
		Verts.push_back((float)OffsetY + Height);

		m_cursor.x += metaFile.m_infoData.Chars[text[i]].XAdvance;
	}

	for (unsigned int i = 0; i < Verts.size(); i++) {
		Verts[i] *= scale;
	}

	addVBO(2, Verts);
	addVBO(2, textureCoords);
	m_vertCount = Verts.size() / 2;

}

void TextObj::bindVAO() const
{
	glBindVertexArray(m_vao);
}

void TextObj::deleteData()
{
	glDeleteVertexArrays(1, &m_vao);
	glDeleteBuffers(m_buffers.size(), m_buffers.data());
	m_buffers.clear();

	m_vboCount = 0;
	m_vao = 0;
}

void TextObj::addVBO(int dimensions, const std::vector<float>& data)
{
	unsigned int vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), data.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(m_vboCount, dimensions, GL_FLOAT, GL_FALSE, 0, nullptr);
	glEnableVertexAttribArray(m_vboCount++);

	m_buffers.push_back(vbo);
}
