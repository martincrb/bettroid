//
// Created by Martin Cristobal on 22/04/2020.
//

#ifndef BETTROID_RENDERER_H
#define BETTROID_RENDERER_H


#include "Component.h"
#include "Mesh.h"
#include "Shader.h"
#include "GameObject.h"

class GameObject;
class Renderer : public Component {
    private:
        unsigned int EBO;
        unsigned int VBO;
        unsigned int  VAO;
        unsigned int texture;
        unsigned int shaderProgram;
        std::shared_ptr<Shader> shader;
        std::shared_ptr<Mesh> mesh;
    public :
        Renderer(std::shared_ptr<Mesh> mesh);
        int init();
        int update(int dT);
        void setShader(std::shared_ptr<Shader> shader);
};


#endif //BETTROID_RENDERER_H
