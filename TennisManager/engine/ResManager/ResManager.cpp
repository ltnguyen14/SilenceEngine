#include "ResManager.h"

ResManager::ResManager()
{
	Texture texture("arrow_box.png");
	m_textures.push_back(texture);

	Texture texture2("gray_bg.png");
	m_textures.push_back(texture2);
}

ResManager::~ResManager()
{
	m_textures.clear();
}
