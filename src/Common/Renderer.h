//
// Created by Martin Cristobal on 22/04/2020.
//

#ifndef BETTROID_RENDERER_H
#define BETTROID_RENDERER_H


class Renderer {
    private:
        GLuint VBO;
        GLuint VAO;
        GLuint shaderProgram;

    public :
        Renderer();
        int init();
        int render();
        void setShaders(const char* vertex_shader_source, const char* fragment_shader_source);
};


#endif //BETTROID_RENDERER_H
