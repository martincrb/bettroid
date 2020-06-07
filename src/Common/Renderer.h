//
// Created by Martin Cristobal on 22/04/2020.
//

#ifndef BETTROID_RENDERER_H
#define BETTROID_RENDERER_H


#include "Component.h"
#include "Mesh.h"
#include "Shader.h"
#include "GameObject.h"
#include "Camera.h"

class GameObject;
class Renderer : public Component {
    private:
        unsigned int EBO;
        unsigned int VBO;
        unsigned int  VAO;
        unsigned int texture;
        std::shared_ptr<Camera> camera;
        std::shared_ptr<Shader> shader;
        std::shared_ptr<Mesh> mesh;
    public :
        Renderer(std::shared_ptr<Mesh> mesh, std::shared_ptr<Camera> camera);
        int init();
        int update(double dT);
        void setShader(std::shared_ptr<Shader> shader);
};


#endif //BETTROID_RENDERER_H
