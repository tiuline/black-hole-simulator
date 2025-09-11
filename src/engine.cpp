#include "Engine.h"
#include <iostream>
#include <cmath>


Engine::Engine()
{
    width = 480;
    height = 360;

    vWidth = 100000000000.0f; 
    vHeight = 75000000000.0f;
    
    offsetX = 0.0f;
    offsetY =  0.0f;
    zoom = 1.0f;
    middleMousePressed = false;
    lastMouseX = 0.0;
    lastMouseY = 0.0;

    if (!glfwInit())
    {
        std::cerr << "Falha ao iniciar o GLFW" <<std::endl;
        exit(EXIT_FAILURE);
    }
    
    window = glfwCreateWindow(width, height, "BHS - Black Hole Simulator", NULL, NULL );
    
    if(!window)
    {
        std::cerr << "Falha ao iniciar a janela GLFW" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    
    if(glewInit() != GLEW_OK)
    {
        std::cerr << "Falha ao iniciar o GLEW" << std::endl;
        glfwDestroyWindow(window);
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glViewport(0,0, width, height);;
}

void Engine::run()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    double left     = -width + offsetX;
    double right    = width + offsetX;
    double bottom   = -height + offsetY;
    double top      = height + offsetY;
    glOrtho(left, right, bottom, top, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

