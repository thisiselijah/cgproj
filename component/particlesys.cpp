#include "particlesys.hpp"

ParticleSystem::ParticleSystem(unsigned int numParticles)
{
    try
    {
        this->numParticles = numParticles;
        particles.reserve(numParticles);

        this->programID = LoadShaders("../shader/particle_v.glsl", "../shader/particle_f.glsl");
        this->textureID = loadTexture("../texture/Fire.jpg");
        if (textureID == 0)
        {
            std::cerr << "Failed to load texture!" << std::endl;
        }

        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);

        glGenBuffers(1, &vertexbuffer);
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_DYNAMIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);

        GLuint uvbuffer;
        glGenBuffers(1, &uvbuffer);
        glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(g_uv_buffer_data), g_uv_buffer_data, GL_STATIC_DRAW);

        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void *)0);

        // glEnableVertexAttribArray(1);
        glEnableVertexAttribArray(0);

        // glBindBuffer(GL_ARRAY_BUFFER, 0);
        // glBindVertexArray(0);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    // this->emit();
}

void ParticleSystem::emit()
{

    try
    {
        particles.resize(numParticles);
        for (unsigned int i = 0; i < numParticles; i++)
        {
            respawn(particles[i]);
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void ParticleSystem::update(float dt)
{
    for (int i = this->particles.size() - 1; i >= 0; i--)
    {
        Particle &p = particles[i];
        p.velocity += p.acceleration2 * dt;
        p.position += p.velocity * dt;
        p.lifetime -= dt;

        // Update color based on remaining lifetime
        float lifeRatio = p.lifetime / 2.0f; // Assuming the maximum lifetime is 2.0f
        p.color = glm::vec4(lifeRatio, lifeRatio, lifeRatio, 1.0f);
        p.color.a = p.lifetime / 4.0f;
        // float lifeRatio = p.lifetime / 2.0f; // Assuming the maximum lifetime is 2.0f
        // p.color = glm::vec4(1.0f, lifeRatio, lifeRatio, 1.0f);
        // p.color.a = p.lifetime / 2.0f;

        if (p.lifetime <= 0.0f)
        {
            respawn(p);
        }
        // if (p.lifetime <= 0.0f)
        // {
        //     particles.erase(particles.begin() + i);
        // }
    }
}

void ParticleSystem::render()
{

    glUseProgram(programID);

    GLuint sizeLocation = glGetUniformLocation(programID, "SIZE");
    // printf("Size Location: %d\n", sizeLocation);
    GLuint colorLocation = glGetUniformLocation(programID, "color");
    // printf("Color Location: %d\n", colorLocation);
    GLuint offsetLocation = glGetUniformLocation(programID, "OF");
    // printf("Offset Location: %d\n", offsetLocation);
    GLuint textureLocation = glGetUniformLocation(programID, "Texture");
    // printf("Texture Location: %d\n", textureLocation);

    glBindVertexArray(VAO);
    glEnableVertexAttribArray(0);

    for (const Particle &p : particles)
    {

        glUniform1f(sizeLocation, p.size);
        glUniform4fv(colorLocation, 1, &p.color[0]);
        glUniform3fv(offsetLocation, 1, &p.position[0]);
        glUniform1i(textureLocation, 0);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, textureID);
        glDrawArrays(GL_TRIANGLES, 0, 36);
    }

    glDisableVertexAttribArray(0);
    glBindVertexArray(0);
}

void ParticleSystem::respawn(Particle &p)
{
    p.position = glm::vec3(0.0f, 0.0f, 0.0f);
    p.acceleration2 = glm::vec3(0.0f, 0.0f, -2.8f);
    do
    {
        p.velocity = glm::sphericalRand(glm::linearRand(0.5f, 12.5f));
        
    } while (p.velocity.z <= 0.0f);
    p.velocity.z = glm::linearRand(2.5f, 12.0f);

    p.color = glm::vec4(
        glm::linearRand(0.8f, 1.0f), // R
        glm::linearRand(0.4f, 0.6f), // G
        glm::linearRand(0.0f, 0.2f), // B
        1.0f                         // A
    );
    // p.color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);

    p.size = glm::linearRand(0.01f, 0.03f);

    // p.size = glm::linearRand(0.2f, 0.5f);
    p.lifetime = glm::linearRand(2.0f, 3.0f);
}