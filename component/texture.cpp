#include "texture.hpp"


GLuint loadTexture(const char *texturePath)
{
	GLuint textureID;
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);

	int width, height, nrChannels;
	unsigned char *data = stbi_load(texturePath, &width, &height, &nrChannels, 0);
	if (data)
	{
		stbi_write_png("../test/output_texture.png", width, height, nrChannels, data, width * nrChannels);
    	std::cout << "Texture exported to output_texture.png" << std::endl;
		GLenum format = (nrChannels == 4) ? GL_RGBA : GL_RGB;
		std::cout << "Texture loaded: " << texturePath
				  << " (Width: " << width << ", Height: " << height
				  << ", Channels: " << nrChannels << ")" << std::endl;
		stbi_set_flip_vertically_on_load(true);
		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cerr << "Failed to load texture: " << texturePath << std::endl;
	}
	stbi_image_free(data);

	// 設置材質參數
	// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	return textureID;
}
