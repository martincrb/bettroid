//
// Created by Martin Cristobal on 22/04/2020.
//

#include "Game.h"
#include "Common/Quad.h"
#include "Behaviours/RotateAroundOrigin.h"
#include "Common/InputProvider.h"

int Game::run() {
    initWindow();
    loadAssets();
    gameLoop();

}

int Game::initWindow() {
    width = 1024;
    height = 768;

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
    window = std::shared_ptr<GLFWwindow>(
            glfwCreateWindow( width, height, "Bettroit", NULL, NULL),
            std::free);


    if( window == NULL ){
        fprintf( stderr, "Falla al abrir una ventana GLFW.\n" );
        glfwTerminate();
        return -1;
    }


    glfwMakeContextCurrent(window.get()); // Inicializar GLEW
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

    auto inputProvider = std::make_shared<InputProvider>(window);

    auto gObject = std::make_shared<GameObject>();
    auto gameCamera = std::make_shared<Camera>((float)width, (float)height);
    gameCamera->setPosition(2, 2, 2);
    auto rotateBehaviour = std::make_shared<RotateAroundOrigin>();
    gameCamera->addComponent(rotateBehaviour);
    auto renderer = std::make_shared<Renderer>(quad, gameCamera);
    renderer->init();
    renderer->setShader(shader);

    gObject->addComponent(renderer);

    Scene scene = Scene();

    scene.addGameObject(gObject);
    scene.addGameObject(gameCamera);

    while (!glfwWindowShouldClose(window.get()))
    {
        //Coger eventos de teclado / ratón
        inputProvider->isKeyDown(GLFW_KEY_A);
        glClearColor(0.2, 0.2, 0.2, 1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        scene.update(glfwGetTime());
        glfwSwapBuffers(window.get());

        glfwPollEvents();
    }

    glfwDestroyWindow(window.get());
    glfwTerminate();
}

int Game::update() {

}
int Game::loadAssets() {

}
