#define STB_IMAGE_IMPLEMENTATION    

#include "Texture.h"
#include "stb_image.h"


Texture::Texture(const std::string& filePath)
{
	int width, height, numComponents;
	std::string fullPath = "res/textures/" + filePath;
	m_name = filePath;
	unsigned char* imageData = stbi_load(fullPath.c_str(), &width, &height, &numComponents, 4);
	
	if (imageData == NULL)
		std::cerr << "Texure Loading failed for texture " << filePath << std::endl;

	glGenTextures(1, &m_TextureID);
	glBindTexture(GL_TEXTURE_2D, m_TextureID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);


	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);

	//stbi_image_free(imageData);
}

Texture::~Texture()
{
	glDeleteTextures(1, &m_TextureID);
}

void Texture::Bind(unsigned int textureID) const
{
	assert(textureID >= 0 && textureID <= 31);
	glActiveTexture(GL_TEXTURE0 + textureID);
	glBindTexture(GL_TEXTURE_2D, m_TextureID);
}
