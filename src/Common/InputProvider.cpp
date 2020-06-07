//
// Created by Martin Cristobal on 07/06/2020.
//

#include <iostream>
#include "InputProvider.h"

bool InputProvider::isKeyDown(int keyNumber) {
    /*
    const float cameraSpeed = 0.05f; // adjust accordingly
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        cameraPos += cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        cameraPos -= cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
        */
    return glfwGetKey(window.get(), keyNumber) == GLFW_PRESS;
}

bool InputProvider::isKeyUp(int keyNumber) {
    return glfwGetKey(window.get(), keyNumber) == GLFW_RELEASE;
}

InputProvider::InputProvider(std::shared_ptr<GLFWwindow> window) : window{window}
{}
