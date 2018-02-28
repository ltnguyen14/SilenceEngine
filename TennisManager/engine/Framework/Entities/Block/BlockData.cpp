#include "BlockData.h"

BlockData::BlockData(const std::string& filePath, std::vector<TextureAtlas*> atlases)
{
	std::ifstream inFile("res/Blocks/" + filePath + ".block");
	glm::vec2 side, top, bottom;

	if (!inFile.is_open())
	{
		std::cout << "Unable to open block file: " + filePath + "!" << std::endl;
	}

	std::string line;
	while (std::getline(inFile, line))
	{
		if (line == "Name") 
		{
			std::string name;
			inFile >> name;
			m_name = name;
		}
		if (line == "TexPath")
		{
			std::string path;
			inFile >> path;
			m_texPath = path;
		}
		if (line == "TexTop")
		{
			int x, y;
			inFile >> x >> y;
			top = { x, y };
		}
		else if (line == "TexSide")
		{
			int x, y;
			inFile >> x >> y;
			side = { x, y };
		}
		else if (line == "TexBottom")
		{
			int x, y;
			inFile >> x >> y;
			bottom = { x, y };
		}
		else if (line == "TexAll")
		{
			int x, y;
			inFile >> x >> y;
			top = { x, y };
			side = { x, y };
			bottom = { x, y };
		}
	}

	TextureAtlas* textAtlas = nullptr;
	for (auto& atlas : atlases) {
		if (atlas->getName() == m_texPath) {
			m_texture = atlas;
			textAtlas = atlas;
		}
	}

	auto texTop = textAtlas->getTexture(top);
	auto texSide = textAtlas->getTexture(side);
	auto texBottom = textAtlas->getTexture(bottom);

	m_texCoords.insert(m_texCoords.end(), texSide.begin(), texSide.end());
	m_texCoords.insert(m_texCoords.end(), texSide.begin(), texSide.end());
	m_texCoords.insert(m_texCoords.end(), texSide.begin(), texSide.end());
	m_texCoords.insert(m_texCoords.end(), texSide.begin(), texSide.end());
	m_texCoords.insert(m_texCoords.end(), texTop.begin(), texTop.end());
	m_texCoords.insert(m_texCoords.end(), texBottom.begin(), texBottom.end());

}
