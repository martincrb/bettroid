//
// Created by Martin Cristobal on 07/06/2020.
//

#ifndef BETTROID_INPUTPROVIDER_H
#define BETTROID_INPUTPROVIDER_H


#include <GLFW/glfw3.h>
#include <memory>

class InputProvider {
private:
    std::shared_ptr<GLFWwindow> window;

public:
    InputProvider(std::shared_ptr<GLFWwindow> window);

    bool isKeyDown(int keyNumber);
    bool isKeyUp(int keyNumber);
};


#endif //BETTROID_INPUTPROVIDER_H
