//
// Created by Martin Cristobal on 25/04/2020.
//

#ifndef BETTROID_DEFAULTBEHAVIOUR_H
#define BETTROID_DEFAULTBEHAVIOUR_H


#include "Component.h"

class DefaultBehaviour: public Component {
public:
    int upate(GameObject *parent) override;

};


#endif //BETTROID_DEFAULTBEHAVIOUR_H
