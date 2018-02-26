#pragma once
#include <vector>
#include "Texture.h"
#include "../../Tools/Math/glm.h"

class TextureAtlas : public Texture {
public:
	TextureAtlas(const std::string& filePath);
	std::vector<float> getTexture(const glm::vec2& coords);

private:
	int m_totalSize = 256;
	int m_textureSize = 16;
};