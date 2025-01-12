#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
public:
    enum class CoordinateMode {
        SPHERICAL,
        CARTESIAN
    };

    glm::vec3 position;
    glm::vec3 target;
    glm::vec3 up;
    glm::mat4 viewMatrix;
    CoordinateMode mode;

    Camera(float radius, float theta, float phi, glm::vec3 target, glm::vec3 up, CoordinateMode mode = CoordinateMode::SPHERICAL);
    void update(float radius, float theta, float phi);
    void update(glm::vec3 position, glm::vec3 target, glm::vec3 up);
};

#endif