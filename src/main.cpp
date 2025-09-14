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
    const double SCALE_METERS_PER_UNIT = 1.268388173965468e10;
    Engine engine;

    engine.run();
    return 0;
}