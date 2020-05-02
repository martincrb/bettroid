//
// Created by Martin Cristobal on 02/05/2020.
//

#ifndef BETTROID_MESH_H
#define BETTROID_MESH_H


#include <GL/glew.h>
#include <vector>

class Mesh {
protected:
    std::vector<GLfloat> vertices;

public:
    Mesh();
    std::vector<int> faces;
    GLfloat* getFirstVertexPointer();
    int      getNumOfVertices();
};


#endif //BETTROID_MESH_H
