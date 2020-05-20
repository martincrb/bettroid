//
// Created by Martin Cristobal on 22/04/2020.
//
#define STB_IMAGE_IMPLEMENTATION
#include "../tools/stb_image.h"

#include <GL/glew.h>
#include <iostream>
#include "Renderer.h"

int Renderer::init() {
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER,
                 mesh->getNumOfVertices()*sizeof(GLfloat),
                 mesh->getFirstVertexPointer(),
                 GL_STATIC_DRAW);
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,
            6*sizeof(int),
            &(mesh->faces.front()),
            GL_STATIC_DRAW);

    glGenTextures(1, &texture);

    int width, height, nrChannels;
    unsigned char *data = stbi_load("../assets/textures/container.jpg", &width, &height, &nrChannels, 0);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);

    return 0;
}

int Renderer::update() {
    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glVertexAttribPointer(
            0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
            3,                  // size
            GL_FLOAT,           // type
            GL_FALSE,           // normalized?
            0,                  // stride
            (void*)0            // array buffer offset
    );
    glEnableVertexAttribArray(0);


    glVertexAttribPointer(
            1,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
            2,                  // size
            GL_FLOAT,           // type
            GL_FALSE,           // normalized?
            0 * sizeof(float),                  // stride
            (void*) (12 * sizeof(float))         // array buffer offset
    );
    glEnableVertexAttribArray(1);


    // Draw the triangle !
    glBindTexture(GL_TEXTURE_2D, texture);
    int textureLocation = glGetUniformLocation(shaderProgram, "ourTexture");
    glUniform1ui(textureLocation, texture);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    return 0;
}

void Renderer::setShaders(const char *vertex_shader_source, const char *fragment_shader_source) {
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertex_shader_source, NULL);
    glCompileShader(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragment_shader_source, NULL);
    glCompileShader(fragmentShader);

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);

    glLinkProgram(shaderProgram);
    // Check the program

    glDetachShader(shaderProgram, vertexShader);
    glDetachShader(shaderProgram, fragmentShader);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

Renderer::Renderer(std::shared_ptr<Mesh> mesh) : mesh{mesh} {}
