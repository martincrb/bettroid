//
// Created by Martin Cristobal on 02/05/2020.
//

#include "Mesh.h"

Mesh::Mesh() {

}

GLfloat* Mesh::getFirstVertexPointer() {
    return &vertices.front();
}

int Mesh::getNumOfVertices() {
    return vertices.size();
}
