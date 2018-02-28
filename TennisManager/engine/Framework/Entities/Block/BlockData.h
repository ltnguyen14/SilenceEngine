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
	inline std::vector<float> getTexTop() { return m_texTop; };
	inline std::vector<float> getTexSide() { return m_texSide; };
	inline std::vector<float> getTexBottom() { return m_texBottom; };

	inline std::string getName() { return m_name; };
	inline Texture* getTexture() { return m_texture; };

private:
	std::string m_name;
	std::string m_texPath;
	Texture* m_texture;
	std::vector<float> m_texCoords;
	std::vector<float> m_texTop;
	std::vector<float> m_texSide;
	std::vector<float> m_texBottom;
};