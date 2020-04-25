//
// Created by Martin Cristobal on 25/04/2020.
//

#ifndef BETTROID_BEHAVIOUR_H
#define BETTROID_BEHAVIOUR_H


#include "GameObject.h"

class Behaviour {
public:
    virtual int update(GameObject* parent) = 0;
};


#endif //BETTROID_BEHAVIOUR_H
