#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP
#include <GL/glew.h>
#include "texture.hpp"
#include "shader.hpp"

class Background
{
public:
    GLfloat g_vertex_buffer_data[18];
    GLfloat g_uv_buffer_data[12] = {
        // 第一個三角形的 UV 座標
        0.0f, 0.0f, // 左下角
        1.0f, 0.0f, // 右下角
        1.0f, 1.0f, // 右上角

        // 第二個三角形的 UV 座標
        0.0f, 0.0f, // 左下角
        1.0f, 1.0f, // 右上角
        0.0f, 1.0f  // 左上角
    };

    GLuint VertexArrayID;
    GLuint vertexbuffer;
    GLuint uvbuffer;
    GLuint programID;
    GLuint textureID;

    Background();
    void render();
};

#endif