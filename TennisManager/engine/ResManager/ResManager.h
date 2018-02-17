#pragma once
#include <vector>
#include "../Tools/Texture/Texture.h"

class ResManager {
public:
	ResManager();
	~ResManager();

private:
	std::vector<Texture> m_textures;
};