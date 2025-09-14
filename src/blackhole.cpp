#include <BlackHole.h>
#include <Constants.h>
#include <cmath>

BlackHole::BlackHole(glm::vec2 pos, double m)
    : position(pos), mass(m)
{
    r_s = (2.0 * G * mass) / (C * C);
}

std::vector<glm::vec2> BlackHole::generateBlackHoleVertices(float radius, int segments) const
{
    std::vector<glm::vec2> vertices;
    vertices.emplace_back(0.0f, 0.0f);

    for (int i = 0; i <= segments; ++i)
    {
        float angle = 2.0f * M_PI * i / segments;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        vertices.emplace_back(x,y);
    }

    return vertices;
}