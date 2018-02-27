#include "ResManager.h"

ResManager::ResManager()
{
	Texture* texture = new Texture("arrow_box.png");
	m_textures.push_back(texture);

	Texture* texture2 = new Texture("gray_bg.png");
	m_textures.push_back(texture2);

	Texture* texture3 = new Texture("arrow-right.png");
	m_textures.push_back(texture3);

	Texture* texture4 = new Texture("../Fonts/roboto.png");
	m_textures.push_back(texture4);

	Texture* texture5 = new Texture("Test.png");
	m_textures.push_back(texture5);

	TextureAtlas* atlas = new TextureAtlas("AtlasTest.png");
	m_textureAtlas.push_back(atlas);

	TextureAtlas* terrain = new TextureAtlas("terrainAtlas.png");
	m_textureAtlas.push_back(terrain);

	BlockData* dirt = new BlockData("Dirt", m_textureAtlas);
	m_blockData.push_back(dirt);

	BlockData* grass = new BlockData("Grass", m_textureAtlas);
	m_blockData.push_back(grass);

	BlockData* stone = new BlockData("Stone", m_textureAtlas);
	m_blockData.push_back(stone);
}

ResManager::~ResManager()
{
	m_textures.clear();
}

Texture* ResManager::getTexture(std::string textureName)
{
	for (auto& texture : m_textures) {
		if (texture->getName() == textureName)
			return texture;
	}
	std::cout << "Cannot find texture " << textureName << std::endl;
}

TextureAtlas * ResManager::getAtlas(std::string atlasName)
{
	for (auto& atlas : m_textureAtlas) {
		if (atlas->getName() == atlasName)
			return atlas;
	}
	std::cout << "Cannot find atlas " << atlasName << std::endl;
}

BlockData * ResManager::getBlockData(std::string blockName)
{
	for (auto& block : m_blockData) {
		if (block->getName() == blockName)
			return block;
	}
	std::cout << "Cannot find atlas " << blockName << std::endl;
}

