#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "../component/particlesys.hpp"
#include "../component/camera.hpp"
#include "../component/background.hpp"
#include "../component/shader.hpp"

GLFWwindow *window;
Camera *camera;
Background *background;
ParticleSystem *particleSystem;
ParticleSystem *particleSystem2;

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if ((key == GLFW_KEY_ESCAPE || key == GLFW_KEY_Q) && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}

void mouse_button_callback(GLFWwindow *window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
    {
        try
        {
            // // Get cursor position
            // double xpos, ypos;
            // glfwGetCursorPos(window, &xpos, &ypos);

            // // Get window size
            // int width, height;
            // glfwGetWindowSize(window, &width, &height);

            // // Convert to NDC
            // float x = (2.0f * xpos) / width - 1.0f;
            // float y = 1.0f - (2.0f * ypos) / height;

            // // Get current MVP matrices
            // glm::mat4 Projection = glm::perspective(glm::radians(45.0f), (float)width/(float)height, 0.1f, 100.0f);
            // glm::mat4 View = camera->viewMatrix;
            // glm::mat4 Model = glm::mat4(1.0f);

            // // Create inverse MVP
            // glm::mat4 invMVP = glm::inverse(Projection * View * Model);

            // // Create ray in world space
            // glm::vec4 rayStart = invMVP * glm::vec4(x, y, -1.0f, 1.0f);
            // glm::vec4 rayEnd = invMVP * glm::vec4(x, y, 1.0f, 1.0f);
            // rayStart /= rayStart.w;
            // rayEnd /= rayEnd.w;

            // // Calculate ray direction
            // glm::vec3 rayDir = glm::normalize(glm::vec3(rayEnd - rayStart));

            // // Intersect with z=0 plane
            // float t = -rayStart.z / rayDir.z;
            // glm::vec3 intersection = glm::vec3(rayStart) + rayDir * t;

            // Emit particles at intersection point
            particleSystem->emit();

            // // Debug output
            // printf("Click at window: (%f, %f)\n", xpos, ypos);
            // printf("World intersection: (%f, %f, %f)\n",
            //        intersection.x, intersection.y, intersection.z);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}

void setup_callbacks()
{
    glfwSetKeyCallback(window, key_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
}

void mainloop()
{
    setup_callbacks();

    // glm::vec3 position = glm::vec3(5.0f, 5.0f, 10.0f);
    // glm::vec3 target = glm::vec3(0.0f);
    // glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
    float radius = 10.0f;
    float theta = glm::radians(170.0f);
    float phi = glm::radians(90.0f);

    while (!glfwWindowShouldClose(window))
    {
        // Clear the color and depth buffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Update camera position
        camera->update(radius, theta, phi);

        // Compute the MVP matrix
        glm::mat4 Projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
        glm::mat4 View = camera->viewMatrix;
        glm::mat4 Model = glm::mat4(1.0f);
        glm::mat4 MVP = Projection * View * Model;

        glBlendFunc(GL_SRC_ALPHA, GL_ONE);
        // glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
        // glBlendFunc(GL_SRC_ALPHA, GL_DST_ALPHA);
        // glBlendFunc(GL_ONE_MINUS_DST_ALPHA, GL_DST_ALPHA);
        // glBlendFunc(GL_DST_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        // glBlendFunc(GL_SRC_ALPHA_SATURATE, GL_ONE_MINUS_SRC_ALPHA);
        // glBlendFunc(GL_SRC_ALPHA_SATURATE, GL_SRC_ALPHA);

        // Pass MVP matrix to shader
        GLuint backgroundMatrixID = glGetUniformLocation(background->programID, "MVP");
        glUniformMatrix4fv(backgroundMatrixID, 1, GL_FALSE, &MVP[0][0]);
        glEnable(GL_DEPTH_TEST);                           // 渲染背景時先開啟深度測試
        glDepthFunc(GL_ALWAYS);                            // 粒子無視背景深度，顯示在所有物件之上
        

        // 渲染背景
        background->render();

        GLuint particleMatrixID = glGetUniformLocation(particleSystem->programID, "MVP");
        // printf("Particle Matrix ID: %d\n", particleMatrixID);
        glUniformMatrix4fv(particleMatrixID, 1, GL_FALSE, &MVP[0][0]);

        glEnable(GL_BLEND);       // 開啟混合模式
        particleSystem->render(); // 渲染粒子系統
        glDisable(GL_BLEND);      // 關閉混合模式
        particleSystem->update(0.01f);
        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <Number of particles>\n", argv[0]);
        return -1;
    }
    unsigned int numParticles = std::atoi(argv[1]);
    if (!glfwInit())
    {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return -1;
    }
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(720, 720, "Particle System", NULL, NULL);
    if (!window)
    {
        fprintf(stderr, "Failed to open GLFW window\n");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        fprintf(stderr, "Failed to initialize GLEW\n");
        return -1;
    }
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    // Initialize camera
    camera = new Camera(10.0f, glm::radians(45.0f), glm::radians(45.0f), glm::vec3(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

    // Initialize background
    background = new Background();

    particleSystem = new ParticleSystem(numParticles);

    GLint maxUniformLength;
    glGetProgramiv(particleSystem->programID, GL_ACTIVE_UNIFORM_MAX_LENGTH, &maxUniformLength);
    std::cout << maxUniformLength << std::endl;

    mainloop();
    glfwTerminate();
    delete particleSystem;
    delete camera;
    delete background;
    return 0;
}
