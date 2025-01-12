/**
 * @file main.cpp
 * @brief Main file for the particle system project.
 * 
 * This file contains the main function and the main loop for the particle system project.
 * It initializes the GLFW window, GLEW, and sets up the camera, background, and particle system.
 * It also handles input callbacks for key presses and mouse button presses.
 * 
 * @author Chao Lin Hsu
 * @date 2025
 */

 /**
    * @brief Key callback function to handle key press events.
    * 
    * This function is called whenever a key is pressed or released.
    * It closes the window if the Escape or Q key is pressed.
    * 
    * @param window The GLFW window.
    * @param key The key that was pressed or released.
    * @param scancode The system-specific scancode of the key.
    * @param action The action (press or release).
    * @param mods Bit field describing which modifier keys were held down.
    */
void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);

/**
 * @brief Mouse button callback function to handle mouse button press events.
 * 
    * This function is called whenever a mouse button is pressed or released.
    * It emits particles from the particle system if the left mouse button is pressed.
    * 
    * @param window The GLFW window.
    * @param button The mouse button that was pressed or released.
    * @param action The action (press or release).
    * @param mods Bit field describing which modifier keys were held down.
    */
void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);

/**
 * @brief Sets up the input callbacks for the GLFW window.
 * 
 * This function sets the key callback and mouse button callback for the GLFW window.
 */
void setup_callbacks();

/**
 * @brief Main loop of the application.
 * 
 * This function contains the main loop of the application.
 * It updates the camera position, computes the MVP matrix, renders the background and particle system,
 * and handles input events.
 */
void mainloop();

/**
 * @brief Main function of the application.
 * 
 * This function initializes the GLFW window, GLEW, and sets up the camera, background, and particle system.
 * It then enters the main loop of the application.
 * 
 * @param argc The number of command-line arguments.
 * @param argv The command-line arguments.
 * @return int Returns 0 on success, or -1 on failure.
 */
int main(int argc, char **argv);

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
            particleSystem->emit();

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

        // Pass MVP matrix to background's shader
        GLuint backgroundMatrixID = glGetUniformLocation(background->programID, "MVP");
        glUniformMatrix4fv(backgroundMatrixID, 1, GL_FALSE, &MVP[0][0]);
        glEnable(GL_DEPTH_TEST);                           
        glDepthFunc(GL_ALWAYS);                            
        

        // render background
        background->render();

        // Pass MVP matrix to particle system's shader
        GLuint particleMatrixID = glGetUniformLocation(particleSystem->programID, "MVP");
        // printf("Particle Matrix ID: %d\n", particleMatrixID);
        glUniformMatrix4fv(particleMatrixID, 1, GL_FALSE, &MVP[0][0]);

        glEnable(GL_BLEND); 
        // render particle system      
        particleSystem->render(); 
        glDisable(GL_BLEND);     
        particleSystem->update(0.01f);

        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

int main(int argc, char **argv)
{
    /*---Parse the passing arguments---*/
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
