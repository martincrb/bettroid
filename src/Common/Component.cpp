//
// Created by Martin Cristobal on 25/04/2020.
//

#include "Component.h"

void Component::setParent(std::weak_ptr<GameObject> parent) {
    this->parent = parent;
}
