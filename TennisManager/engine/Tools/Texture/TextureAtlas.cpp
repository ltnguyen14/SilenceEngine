#include "TextureAtlas.h"

TextureAtlas::TextureAtlas(const std::string & filePath)
	:Texture(filePath)
{
}

std::vector<float> TextureAtlas::getTexture(const glm::vec2 & coords)
{
	static const float TEX_PER_ROW = (float)m_totalSize / (float)m_textureSize;
	static const float INDV_TEX_SIZE = 1.0f / TEX_PER_ROW;
	static const float PIXEL_SIZE = 1.0f / (float)m_totalSize;

	float xMin = (coords.x * INDV_TEX_SIZE) + 0.5 * PIXEL_SIZE;
	float yMin = (coords.y * INDV_TEX_SIZE) + 0.5 * PIXEL_SIZE;

	float xMax = (xMin + INDV_TEX_SIZE) - 0.5 * PIXEL_SIZE;
	float yMax = (yMin + INDV_TEX_SIZE) - 0.5 * PIXEL_SIZE;

	return
	{
		xMax, yMax,
		xMin, yMax,
		xMin, yMin,
		xMax, yMin
	};
}
