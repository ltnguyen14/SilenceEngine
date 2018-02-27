#pragma once
#include <vector>
#include "../Tools/Texture/Texture.h"
#include "../Tools/Texture/TextureAtlas.h"
#include "../Framework/Entities/Block/BlockData.h"

class ResManager {
public:
	ResManager();
	~ResManager();

	Texture* getTexture(std::string textureName);
	TextureAtlas* getAtlas(std::string atlasName);
	BlockData* getBlockData(std::string blockName);

private:
	std::vector<Texture*> m_textures;
	std::vector<TextureAtlas*> m_textureAtlas;
	std::vector<BlockData*> m_blockData;
};