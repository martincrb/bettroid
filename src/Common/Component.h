//
// Created by Martin Cristobal on 25/04/2020.
//

#ifndef BETTROID_COMPONENT_H
#define BETTROID_COMPONENT_H


//#include "GameObject.h"

#include <memory>
#include <string>

class GameObject;
class Component {

protected:
    std::weak_ptr<GameObject> parent;

public:
    void setParent(std::weak_ptr<GameObject> parent);
    std::shared_ptr<GameObject> getParent();
    virtual int update(double dT) = 0;
};


#endif //BETTROID_COMPONENT_H
