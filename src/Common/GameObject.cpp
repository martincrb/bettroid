//
// Created by Martin Cristobal on 25/04/2020.
//

#include "GameObject.h"
GameObject::GameObject() {}

void GameObject::setParent(std::shared_ptr<GameObject> parent) {
    this->parent = parent;
}

void GameObject::addChildren(std::shared_ptr<GameObject> child) {
    child->setParent(shared_from_this());
    children.push_back(child);
}

void GameObject::addComponent(std::shared_ptr<Component> component) {
    component->setParent(shared_from_this());
    components.push_back(component);
}

void GameObject::removeChildrenAt(int index) {
    // Remove items from an array is lineal O(n)
    children.erase(children.begin() + index);
}

int GameObject::update() {
    for (auto& component : components) {
        component->update();
    }

    for (auto& child : children) {
        child->update();
    }
    return 0;
}
