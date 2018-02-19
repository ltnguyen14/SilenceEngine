#include "SilenceEngine.h"

SilenceEngine::SilenceEngine(int width, int height, std::string title)
	:m_window(new Window(width, height, title))
{ 
}

SilenceEngine::~SilenceEngine()
{
}

void SilenceEngine::drawQuad(glm::vec2 position, float width, float height, glm::vec4 color, std::string textureName)
{
	m_renderSystem->drawQuad(position, width, height, color, textureName);
}
