#define GLM_ENABLE_EXPERIMENTAL
#include "Ray.h"
#include <glm/gtx/norm.hpp>

Ray::Ray(glm::vec2 pos, glm::vec2 dir)
    : position(pos)
{
    direction = glm::normalize(dir);
}

void Ray::step(float distance)
{
    position += direction * distance;
}
