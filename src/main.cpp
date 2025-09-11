#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include <iostream>
#include <Engine.h>
#define _USE_MATH_DEFINES
#include <cmath>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
using namespace glm;
using namespace std;


int main()
{
    Engine engine;

    while(!glfwWindowShouldClose(engine.window))
    {
        engine.run();

        glfwSwapBuffers(engine.window);
        glfwPollEvents();
    }
    return 0;
}