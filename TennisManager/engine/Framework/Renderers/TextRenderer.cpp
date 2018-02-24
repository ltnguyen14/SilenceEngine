#include "TextRenderer.h"

TextRenderer::TextRenderer()
	: m_shader("res/shaders/text.shader"), m_metaFile("res/Fonts/roboto.fnt", "../Fonts/roboto.png")
{
}

TextRenderer::~TextRenderer()
{
	m_texts.clear();
}

void TextRenderer::RenderText(Window* window)
{
	m_metaFile.m_textureAtlas.Bind(0);
	m_shader.Bind();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDisable(GL_DEPTH_TEST);

	for (auto& textObj : m_texts) {
		glm::vec4 color = textObj->getColor();
		glm::vec2 position = textObj->getPosition();

		textObj->bindVAO();
		m_shader.SetUniform4f("colour", { color.r, color.g, color.b, 0 });
		m_shader.SetUniformMat4("projViewMatrix", makeOrthoMatrix(window));
		m_shader.SetUniformMat4("modelMatrix", makeModelMatrix({ position.x, position.y, 0 }, { 0, 0, 0 }));

		glDrawArrays(GL_TRIANGLES, 0, textObj->getVertCount());
		delete(textObj);
	}

	m_texts.clear();
	glDisable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);
}

void TextRenderer::AddText(std::string text, glm::vec2 position, float width, glm::vec4 color, bool CENTER_FLAG)
{
	TextObj* textObj = new TextObj();
	textObj->AddData(text, position, width, color, CENTER_FLAG, m_metaFile);
	m_texts.push_back(textObj);
}

