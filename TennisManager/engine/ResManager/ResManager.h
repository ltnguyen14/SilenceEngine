#pragma once
#include <vector>
#include "../Tools/Texture/Texture.h"
#include "../Tools/Texture/TextureAtlas.h"

class ResManager {
public:
	ResManager();
	~ResManager();

	Texture* getTexture(std::string textureName);
	TextureAtlas* getAtlas(std::string atlasName);

private:
	std::vector<Texture*> m_textures;
	std::vector<TextureAtlas*> m_textureAtlas;
};