#include "background.hpp"

Background::Background()
{
    // Initialize vertex buffer data for a quad in the xy plane using two triangles
    g_vertex_buffer_data[0] = -5.0f;
    g_vertex_buffer_data[1] = -5.0f;
    g_vertex_buffer_data[2] = 0.0f;
    g_vertex_buffer_data[3] = 5.0f;
    g_vertex_buffer_data[4] = -5.0f;
    g_vertex_buffer_data[5] = 0.0f;
    g_vertex_buffer_data[6] = 5.0f;
    g_vertex_buffer_data[7] = 5.0f;
    g_vertex_buffer_data[8] = 0.0f;

    g_vertex_buffer_data[9] = -5.0f;
    g_vertex_buffer_data[10] = -5.0f;
    g_vertex_buffer_data[11] = 0.0f;
    g_vertex_buffer_data[12] = 5.0f;
    g_vertex_buffer_data[13] = 5.0f;
    g_vertex_buffer_data[14] = 0.0f;
    g_vertex_buffer_data[15] = -5.0f;
    g_vertex_buffer_data[16] = 5.0f;
    g_vertex_buffer_data[17] = 0.0f;

    programID = LoadShaders("../shader/background_v.glsl", "../shader/background_f.glsl");
    textureID = loadTexture("../texture/metal.png");

    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

    glGenBuffers(1, &uvbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_uv_buffer_data), g_uv_buffer_data, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Background::render()
{
    glUseProgram(this->programID);
    glBindVertexArray(VertexArrayID);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);

    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
    glVertexAttribPointer(
        1,        // UV屬性位置
        2,        // UV每個頂點有2個分量
        GL_FLOAT, // 類型
        GL_FALSE, // 是否規範化
        0,        // 間距
        (void *)0 // 偏移量
    );

    GLuint textureLocation = glGetUniformLocation(programID, "Texture");
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureID);

    glDrawArrays(GL_TRIANGLES, 0, 6); // Use GL_TRIANGLES to draw the quad

    glDisableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}