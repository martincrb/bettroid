//
// Created by Martin Cristobal on 22/04/2020.
//

#ifndef BETTROID_RENDERER_H
#define BETTROID_RENDERER_H


#include "Component.h"
#include "Mesh.h"

class Renderer : public Component {
    private:
        unsigned int EBO;
        unsigned int VBO;
        unsigned int  VAO;
        unsigned int texture;
        unsigned int shaderProgram;
        std::shared_ptr<Mesh> mesh;
    public :
        Renderer(std::shared_ptr<Mesh> mesh);
        int init();
        int update();
        void setShaders(const char* vertex_shader_source, const char* fragment_shader_source);
};


#endif //BETTROID_RENDERER_H
