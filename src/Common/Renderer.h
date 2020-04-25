//
// Created by Martin Cristobal on 22/04/2020.
//

#ifndef BETTROID_RENDERER_H
#define BETTROID_RENDERER_H


#include "Component.h"
class Renderer : public Component {
    private:
        unsigned int VBO;
        unsigned int  VAO;
        unsigned int shaderProgram;

    public :
        Renderer();
        int init();
        int update();
        void setShaders(const char* vertex_shader_source, const char* fragment_shader_source);
};


#endif //BETTROID_RENDERER_H
