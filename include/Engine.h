#ifndef ENGINE_H
#define ENGINE_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <BlackHole.h>

class Engine
{
    private:
        GLuint blackHoleVAO;
        GLuint blackHoleVBO;
        int blackHoleVertexCount;
        GLuint shaderProgram;

        void initBlackHoleCircle(float radius);
        GLuint compileShader(const char* vertexSrc, const char* fragmentSrc);

    public:
        GLFWwindow* window;
        int width;
        int height;
        
        float offsetX, offsetY;
        float zoom;
        bool middleMousePressed;
        double lastMouseX, lastMouseY;
        
        Engine();
        ~Engine();
        void run();
};

#endif