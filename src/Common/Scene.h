//
// Created by Martin Cristobal on 25/04/2020.
//

#ifndef BETTROID_SCENE_H
#define BETTROID_SCENE_H


#include <vector>
#include "GameObject.h"

class Scene {
private:
    std::vector<std::shared_ptr<GameObject>> entities;

public:
    int update(double dT);
    void addGameObject(std::shared_ptr<GameObject> gameObject);
};


#endif //BETTROID_SCENE_H
