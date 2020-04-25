//
// Created by Martin Cristobal on 25/04/2020.
//

#ifndef BETTROID_COMPONENT_H
#define BETTROID_COMPONENT_H


//#include "GameObject.h"

#include <memory>

class GameObject;
class Component {

private:
    std::weak_ptr<GameObject> parent;
public:
    void setParent(std::weak_ptr<GameObject> parent);
    virtual int update() = 0;
};


#endif //BETTROID_COMPONENT_H
