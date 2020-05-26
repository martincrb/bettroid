//
// Created by Martin Cristobal on 02/05/2020.
//

#include "Quad.h"

Quad::Quad() {
    vertices = {
            // positions        //text coords
            0.5f,  0.5f, 0.0f,  // top right
            0.5f, -0.5f, 0.0f,  // bottom right
            -0.5f, -0.5f, 0.0f, // bottom left
            -0.5f,  0.5f, 0.0f,   // top left
            2.0f, 2.0f,
            2.0f, 0.0f,
            0.0f, 0.0f,
            0.0f, 2.0f
    };

    faces = {  // note that we start from 0!
            0, 1, 3,   // first triangle
            1, 2, 3    // second triangle
    };
}