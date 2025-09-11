#ifndef ENGINE_H
#define ENGINE_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Engine
{
public:
    GLFWwindow* window;
    int width;
    int height;

    float vWidth; 
    float vHeight;
    
    float offsetX, offsetY;
    float zoom;
    bool middleMousePressed;
    double lastMouseX, lastMouseY;

    Engine();
    void run();
};

#endif