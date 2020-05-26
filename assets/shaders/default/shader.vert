#version 330 core
layout(location = 0) in vec3 vertexPosition_modelspace;
layout (location = 1) in vec2 aTexCoord;

out vec2 TexCoord;

uniform mat4 transform;

void main()
{
    gl_Position = transform * vec4(vertexPosition_modelspace.xyz, 1.0f);
    TexCoord = aTexCoord;
}