#include "background.hpp"

/**
 * @brief Constructs a Background object.
 * 
 * This constructor initializes the vertex buffer data for a quad in the xy plane using two triangles.
 * It also loads the shaders and texture, and sets up the vertex array and buffer objects.
 * 
 * Vertex buffer data:
 * - Two triangles forming a quad in the xy plane with vertices at (-5, -5, 0), (5, -5, 0), (5, 5, 0), and (-5, 5, 0).
 * 
 * Shaders:
 * - Vertex shader: "../shader/background_v.glsl"
 * - Fragment shader: "../shader/background_f.glsl"
 * 
 * Texture:
 * - "../texture/metal.png"
 * 
 * OpenGL setup:
 * - Generates and binds a vertex array object.
 * - Generates and binds vertex and UV buffer objects, and uploads the data to the GPU.
 * - Unbinds the buffer and vertex array objects.
 */
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

/**
 * @brief Renders the background using OpenGL.
 * 
 * This function sets up the necessary OpenGL state and draws the background
 * using the specified shaders, vertex arrays, and textures.
 * 
 * It performs the following steps:
 * 1. Uses the shader program associated with this background.
 * 2. Binds the vertex array object.
 * 3. Enables and sets up the vertex attribute arrays for position and UV coordinates.
 * 4. Binds the vertex and UV buffers.
 * 5. Sets the texture uniform and binds the texture.
 * 6. Draws the background as a quad using GL_TRIANGLES.
 * 7. Disables the vertex attribute arrays and unbinds the buffers and vertex array.
 */
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
        1,        
        2,        
        GL_FLOAT, 
        GL_FALSE, 
        0,        
        (void *)0 
    );

    GLuint textureLocation = glGetUniformLocation(programID, "Texture");
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureID);

    glDrawArrays(GL_TRIANGLES, 0, 6); // Use GL_TRIANGLES to draw the quad

    glDisableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}