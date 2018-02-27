#pragma once
#include <vector>
#include <string>
#include <fstream>
#include "../../../Tools/Texture/Texture.h"
#include "../../../Tools/Texture/TextureAtlas.h"

class BlockData {
public:
	BlockData(const std::string& filePath, std::vector<TextureAtlas*> atlases);
	~BlockData() {};

	inline std::vector<float> getTexCoords() { return m_texCoords; };
	inline std::string getName() { return m_name; };
	inline std::string getTexPath() { return m_texturePath; };

private:
	std::string m_name;
	std::string m_texturePath;
	std::vector<float> m_texCoords;
};