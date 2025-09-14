#ifndef ENGINE_H
#define ENGINE_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <BlackHole.h>
#include <Ray.h> // Certifique-se de incluir corretamente
#include <vector>

class Engine
{
    private:
        GLuint blackHoleVAO;
        GLuint blackHoleVBO;
        int blackHoleVertexCount;
        GLuint shaderProgram;

        void initBlackHoleCircle(float radius);
        GLuint compileShader(const char* vertexSrc, const char* fragmentSrc);

        std::vector<Ray> rays;
        std::vector<std::vector<glm::vec2>> rayTrails; // Guarda o caminho de cada raio

        void initRays();
        void updateRays(float deltaTime);
        void renderRays();

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