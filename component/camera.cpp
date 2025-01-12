#include "camera.hpp"

Camera::Camera(float radius, float theta, float phi, glm::vec3 target, glm::vec3 up, CoordinateMode mode)
    : target(target), up(up), mode(mode) {
    update(radius, theta, phi);
}

void Camera::update(float radius, float theta, float phi) {
    if (mode == CoordinateMode::SPHERICAL) {
        position = glm::vec3(
            radius * sin(theta) * cos(phi),
            radius * cos(theta),
            radius * sin(theta) * sin(phi)
        );
    }
    viewMatrix = glm::lookAt(position, target, up);
}

void Camera::update(glm::vec3 position, glm::vec3 target, glm::vec3 up) {
    if (mode == CoordinateMode::CARTESIAN) {
        this->position = position;
        this->target = target;
        this->up = up;
    }
    viewMatrix = glm::lookAt(this->position, this->target, this->up);
}