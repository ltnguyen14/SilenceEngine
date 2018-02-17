#pragma once

#include <string>
#include <cassert>
#include <iostream>
#include <GL/glew.h>


class Texture {
public:
	Texture(const std::string& filePath);
	virtual ~Texture();

	void Bind(unsigned int textureID) const;

	inline unsigned int getTextureID() const { return m_TextureID; };
	inline std::string getName() const { return m_name; };

private:
	unsigned int m_TextureID;
	std::string m_name;
};