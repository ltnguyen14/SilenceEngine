#include "GUIRenderer.h"

GUIRenderer::GUIRenderer()
	:m_shader("res/shaders/gui.shader")
{
}

GUIRenderer::~GUIRenderer()
{
}

void GUIRenderer::renderGUI(GuiEntity & gui)
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDisable(GL_DEPTH_TEST);

	// Shader and texture
	m_shader.Bind();
	m_shader.SetUniform4f("colour", gui.getColor());
	gui.getTexture()->Bind(0);
	//m_shader.SetUniformMat4("modelMatrix", makeModelMatrix({ std::get<1>(gui),{ 0, 0, 0 } }));

	// VAO
	gui.bindVAO();
	glDrawArrays(GL_TRIANGLE_STRIP, 0, gui.getVertexCount());

	glDisable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);
}
