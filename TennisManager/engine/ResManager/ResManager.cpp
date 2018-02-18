#include "ResManager.h"

ResManager::ResManager()
{
	Texture* texture = new Texture("arrow_box.png");
	m_textures.push_back(texture);

	Texture* texture2 = new Texture("gray_bg.png");
	m_textures.push_back(texture2);

	Texture* texture3 = new Texture("arrow-right.png");
	m_textures.push_back(texture3);
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
