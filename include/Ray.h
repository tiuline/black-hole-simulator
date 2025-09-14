#ifndef RAY_H
#define RAY_H

#include <glm/glm.hpp>

struct Ray {
    glm::vec2 position;
    glm::vec2 direction;

    Ray(glm::vec2 pos, glm::vec2 dir);

    void step(float distance);
};

#endif
