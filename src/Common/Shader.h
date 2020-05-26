//
// Created by Martin Cristobal on 22/04/2020.
//

#ifndef BETTROID_SHADER_H
#define BETTROID_SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

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
};


#endif //BETTROID_SHADER_H
