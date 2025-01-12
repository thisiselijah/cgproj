#ifndef TEXTURE_HPP
#define TEXTURE_HPP
#include <GL/glew.h>
#include <iostream>
#include "stb_image.h"
#include "stb_image_write.h"

GLuint loadTexture(const char *texturePath);

#endif