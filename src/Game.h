//
// Created by Martin Cristobal on 22/04/2020.
//

#ifndef BETTROID_GAME_H
#define BETTROID_GAME_H

#include<iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "Common/Renderer.h"

class Game {
private:
    GLFWwindow* window;

    int initWindow();
    int loadAssets();
    int gameLoop();
    int processLogic();
    int render(Renderer* renderer);
public:
    int run();
};


#endif //BETTROID_GAME_H
