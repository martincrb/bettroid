//
// Created by Martin Cristobal on 25/04/2020.
//
#ifndef BETTROID_GAMEOBJECT_H
#define BETTROID_GAMEOBJECT_H
#include <vector>
#include "Component.h"
#include "Transform.h"

class GameObject : public std::enable_shared_from_this<GameObject> {
private:
    std::weak_ptr<GameObject> parent;
    std::vector<std::shared_ptr<GameObject>> children;
    std::vector<std::shared_ptr<Component>> components;
    std::shared_ptr<Transform> transform;

public:
    GameObject();
    void addComponent(std::shared_ptr<Component> component);
    void addChildren(std::shared_ptr<GameObject> child);
    void setParent(std::shared_ptr<GameObject> parent);
    void removeChildrenAt(int index);
    std::shared_ptr<Transform> getTransform();
    std::shared_ptr<GameObject> getParent();
    int update(int dT);
};
#endif //BETTROID_GAMEOBJECT_H
