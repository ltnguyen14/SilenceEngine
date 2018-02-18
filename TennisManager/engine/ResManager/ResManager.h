#pragma once
#include <vector>
#include "../Tools/Texture/Texture.h"

class ResManager {
public:
	ResManager();
	~ResManager();

	Texture* getTexture(std::string textureName);

private:
	std::vector<Texture*> m_textures;
};