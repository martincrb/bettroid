cmake_minimum_required(VERSION 3.16)
project(Bettroid)

find_package(GLEW REQUIRED)
find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)

set(CMAKE_CXX_STANDARD 14)

add_executable(Bettroid
        src/main.cpp
        src/Common/Renderer.cpp
        src/Common/Renderer.h
        src/Common/Shader.cpp
        src/Common/Shader.h
        src/Common/Transform.cpp
        src/Common/Transform.h
        src/Common/GameObject.cpp
        src/Common/GameObject.h
        src/Common/Scene.cpp
        src/Common/Scene.h
        src/Common/Component.cpp
        src/Common/Component.h
        src/Common/Behaviour.cpp
        src/Common/Behaviour.h
        src/Game.cpp
        src/Game.h src/Common/Mesh.cpp src/Common/Mesh.h src/Common/Quad.cpp src/Common/Quad.h)

target_link_libraries(Bettroid GLEW::GLEW glfw OpenGL::GL)
