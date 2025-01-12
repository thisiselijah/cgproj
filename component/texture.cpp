#include "texture.hpp"

/**
 * @brief Loads a texture from a file and generates an OpenGL texture object.
 *
 * This function loads an image from the specified file path, creates an OpenGL texture object,
 * and sets the necessary texture parameters. It also exports the loaded texture to a PNG file
 * for verification purposes.
 *
 * @param texturePath The file path to the texture image.
 * @return The OpenGL texture ID of the loaded texture.
 *
 * The function performs the following steps:
 * - Generates a texture ID and binds it to GL_TEXTURE_2D.
 * - Loads the image data using the stb_image library.
 * - If the image is successfully loaded, it exports the texture to a PNG file and logs the texture details.
 * - Sets the texture format based on the number of channels in the image.
 * - Flips the image vertically before uploading it to the GPU.
 * - Uploads the image data to the GPU and generates mipmaps.
 * - Sets texture wrapping parameters to GL_CLAMP_TO_EDGE.
 * - Frees the image data after uploading it to the GPU.
 *
 * If the image fails to load, an error message is logged.
 */
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

	// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	return textureID;
}
