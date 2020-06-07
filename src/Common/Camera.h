//
// Created by Martin Cristobal on 07/06/2020.
//

#ifndef BETTROID_CAMERA_H
#define BETTROID_CAMERA_H


#include "GameObject.h"

class Camera : public GameObject {
protected:
    glm::vec3 cameraTarget;
    glm::vec3 cameraDirection;
    glm::vec3 up;
    glm::vec3 cameraRight;
    glm::vec3 cameraUp;
    glm::mat4 view;
    float SCR_WIDTH;
    float SCR_HEIGHT;
    glm::mat4 projection;
public:
    const glm::mat4 &getView() const;

    void setView(const glm::mat4 &view);

    const glm::mat4 &getProjection() const;

    void setProjection(const glm::mat4 &projection);

    void setPosition(float x, float y, float z);

    void setRotation(float x, float y, float z);
public:
    Camera(float width, float height);

    int update(double dT) override;
};


#endif //BETTROID_CAMERA_H
