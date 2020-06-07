//
// Created by Martin Cristobal on 07/06/2020.
//

#ifndef BETTROID_ROTATEAROUNDORIGIN_H
#define BETTROID_ROTATEAROUNDORIGIN_H


#include "../Common/Behaviour.h"
#include "../Common/GameObject.h"

class RotateAroundOrigin : public Behaviour {
public:
    int update(double dT) override;

};


#endif //BETTROID_ROTATEAROUNDORIGIN_H
