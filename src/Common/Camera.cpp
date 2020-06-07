//
// Created by Martin Cristobal on 07/06/2020.
//

#include "Camera.h"

Camera::Camera(float width, float height) :
    SCR_WIDTH{width},
    SCR_HEIGHT{height},
    cameraTarget {glm::vec3(0.0f, 0.0f, 0.0f)},
    cameraDirection {glm::normalize(transform->getPosition() - cameraTarget)},
    // ??
    up {glm::normalize(transform->getRotation())},
    cameraRight {glm::normalize(glm::cross(up, cameraDirection))},
    cameraUp {glm::cross(cameraDirection, cameraRight)},
    view {glm::lookAt(transform->getPosition(),
            cameraTarget,
            up)},
    projection {glm::perspective(
            glm::radians(45.0f),
            SCR_WIDTH / SCR_HEIGHT,
            0.1f,
            100.0f)}
{}

const glm::mat4 &Camera::getView() const {
    return view;
}

void Camera::setView(const glm::mat4 &view) {
    Camera::view = view;
}

const glm::mat4 &Camera::getProjection() const {
    return projection;
}

void Camera::setProjection(const glm::mat4 &projection) {
    Camera::projection = projection;
}

void Camera::setPosition(float x, float y, float z) {
    transform->setPosition(x, y, z);
    view = glm::lookAt(transform->getPosition(),
                cameraTarget,
                       //??
                       glm::vec3(0, 1, 0));
}

void Camera::setRotation(float x, float y, float z) {
    transform->setRotation(x, y, z);
    view = glm::lookAt(transform->getPosition(),
                       cameraTarget,
                        //??
                       glm::vec3(0, 1, 0));
}

int Camera::update(double dT) {
    // Computing unnecessary frames
    view = glm::lookAt(transform->getPosition(),
                       cameraTarget,
            //??
                       glm::vec3(0, 1, 0));
    return GameObject::update(dT);
}
