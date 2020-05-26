//
// Created by Martin Cristobal on 22/04/2020.
//

#include "Transform.h"

void Transform::computeTransformMatrix() {
    trans = glm::mat4(1.0f);
    trans = glm::rotate(trans, glm::radians(rotation[0]), glm::vec3(1.0, 0.0, 0.0));
    trans = glm::rotate(trans, glm::radians(rotation[1]), glm::vec3(0.0, 1.0, 0.0));
    trans = glm::rotate(trans, glm::radians(rotation[2]), glm::vec3(0.0, 0.0, 1.0));
    trans = glm::scale(trans, scale);
    trans = glm::translate(trans, position);
}

Transform::Transform() {
    position = glm::vec3(0, 0, 0);
    rotation = glm::vec3(0, 0, 0);
    scale = glm::vec3(1, 1, 1);
    computeTransformMatrix();
}

void Transform::setPosition(float x, float y, float z) {
    position[0] = x;
    position[1] = y;
    position[2] = z;
    computeTransformMatrix();
}

void Transform::setRotation(float x, float y, float z) {
    rotation[0] = x;
    rotation[1] = y;
    rotation[2] = z;
    computeTransformMatrix();
}

void Transform::setScale(float x, float y, float z) {
    scale[0] = x;
    scale[1] = y;
    scale[2] = z;
    computeTransformMatrix();
}

glm::vec3 Transform::getPosition() {
    return position;
}

glm::vec3 Transform::getRotation() {
    return rotation;
}
glm::vec3 Transform::getScale() {
    return scale;
}