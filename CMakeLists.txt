cmake_minimum_required(VERSION 3.16)
project(Bettroid)

find_package(GLEW REQUIRED)
find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)

set(CMAKE_CXX_STANDARD 14)

add_executable(Bettroid
        src/main.cpp src/Common/Renderer.cpp src/Common/Renderer.h src/Common/Shader.cpp src/Common/Shader.h src/Common/Transform.cpp src/Common/Transform.h src/Game.cpp src/Game.h)

target_link_libraries(Bettroid GLEW::GLEW glfw OpenGL::GL)
