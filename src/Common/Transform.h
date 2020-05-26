//
// Created by Martin Cristobal on 22/04/2020.
//

#ifndef BETTROID_TRANSFORM_H
#define BETTROID_TRANSFORM_H


#include "Component.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class GameObject;
class Transform {
public:
    glm::mat4 trans;
    void setParent(std::weak_ptr<GameObject> parent);
    void setPosition(float x, float y, float z);
    void setRotation(float x, float y, float z);
    void setScale(float x, float y, float z);
    glm::vec3 getPosition();
    glm::vec3 getRotation();
    glm::vec3 getScale();
    Transform();
private:
    std::weak_ptr<GameObject> parent;
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;
    void computeTransformMatrix();

};


#endif //BETTROID_TRANSFORM_H
