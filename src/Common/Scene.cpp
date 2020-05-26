//
// Created by Martin Cristobal on 25/04/2020.
//

#include <iostream>
#include "Scene.h"

int Scene::update(int dT) {
    for (auto& gameObject : entities) {
        gameObject->update(dT);
    }
    return 0;
}

void Scene::addGameObject(std::shared_ptr<GameObject> gameObject) {
    this->entities.push_back(gameObject);
}
