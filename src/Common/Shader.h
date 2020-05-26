//
// Created by Martin Cristobal on 22/04/2020.
//

#ifndef BETTROID_SHADER_H
#define BETTROID_SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/mat4x4.hpp>

class Shader {
public:
    // the program ID
    unsigned int shaderProgramId;

    // constructor reads and builds the shader
    Shader(const char* vertexPath, const char* fragmentPath);
    // use/activate the shader
    void use();
    // utility uniform functions
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
    void setUint(const std::string &name, int value) const;
    void setMatrix4(const std::string &name, glm::mat4 value) const;
};


#endif //BETTROID_SHADER_H
