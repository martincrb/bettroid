//
// Created by Martin Cristobal on 07/06/2020.
//

#include <cmath>
#include <iostream>
#include "RotateAroundOrigin.h"

int RotateAroundOrigin::update(double dT) {
    float camX = sin(dT/2) * 2.0;
    float camZ = cos(dT/2) * 2.0;
    getParent()->getTransform()->setPosition(camX, 2, camZ);
    return Behaviour::update(dT);
}
