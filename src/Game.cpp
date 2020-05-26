//
// Created by Martin Cristobal on 22/04/2020.
//

#include "Game.h"
#include "Common/Quad.h"

int Game::run() {
    initWindow();
    loadAssets();
    gameLoop();

}

int Game::initWindow() {
    int width = 1024;
    int height = 768;

    if( !glfwInit() )
    {
        fprintf( stderr, "Error al inicializar GLFW\n" );
        return -1;
    }
    glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // Queremos OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // Para hacer feliz a MacOS ; Aunque no debería ser necesaria
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //No queremos el viejo OpenGL

    window = glfwCreateWindow( width, height, "Bettroit", NULL, NULL);


    if( window == NULL ){
        fprintf( stderr, "Falla al abrir una ventana GLFW.\n" );
        glfwTerminate();
        return -1;
    }


    glfwMakeContextCurrent(window); // Inicializar GLEW
    glewExperimental=true; // Se necesita en el perfil de base.
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Falló al inicializar GLEW\n");
        return -1;
    }
    return 0;
}

int Game::gameLoop() {
    std::shared_ptr<Mesh> mesh = std::make_shared<Mesh>();
    std::shared_ptr<Quad> quad = std::make_shared<Quad>();//std::static_pointer_cast<Quad>(mesh);
    std::shared_ptr<Shader> shader = std::make_shared<Shader>(
            "../assets/shaders/default/shader.vert",
            "../assets/shaders/default/shader.frag");

    auto triangleRenderer = std::make_shared<Renderer>(quad);
    triangleRenderer->init();
    triangleRenderer->setShader(shader);

    auto redTriangleOfDeath = std::make_shared<GameObject>();
    redTriangleOfDeath->addComponent(triangleRenderer);

    Scene bossFight = Scene();
    bossFight.addGameObject(redTriangleOfDeath);


    while (!glfwWindowShouldClose(window))
    {
        //Coger eventos de teclado / ratón
        glClearColor(0.2, 0.2, 0.2, 1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        bossFight.update();
        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
}

int Game::update() {

}
int Game::loadAssets() {

}
