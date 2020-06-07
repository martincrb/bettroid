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
#include "Common/Scene.h"

class Game {
private:
    std::shared_ptr<GLFWwindow> window;
    std::unique_ptr<Scene> currentScene;
    int width;
    int height;
    int initWindow();
    int loadAssets();
    int gameLoop();
    int update();
public:
    int run();
};


#endif //BETTROID_GAME_H
