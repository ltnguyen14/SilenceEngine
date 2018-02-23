#pragma once
#include <string>
#include <GL/glew.h>
#include "../../Tools/Math/glm.h"
#include "../Text/MetaFile.h"
#include "../../Tools/Shader/Shader.h"
#include "../Text/TextObj.h"

class TextRenderer {

public:
	TextRenderer();
	~TextRenderer();

	void RenderText(Window* window);
	void AddText(std::string text, glm::vec2 position, float width, glm::vec4 color);

private:

private:
	MetaFile m_metaFile;
	Shader m_shader;
	std::vector<TextObj*> m_texts;
};