#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include <iostream>

#include <Engine.h>
#include <BlackHole.h>

#include <cmath>

using namespace glm;
using namespace std;

int main()
{
    Engine engine;

    engine.run();
    return 0;
}