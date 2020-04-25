//
// Created by Martin Cristobal on 25/04/2020.
//

#ifndef BETTROID_BEHAVIOUR_H
#define BETTROID_BEHAVIOUR_H


#include "Component.h"

class Behaviour: public Component {
public:
    int update() override;

};


#endif //BETTROID_BEHAVIOUR_H
