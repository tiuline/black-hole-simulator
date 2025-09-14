#ifndef BLACK_HOLE_H
#define BLACK_HOLE_H

#include <glm/glm.hpp>
#include <Constants.h>
#include <vector>

class BlackHole 
{
public:
    glm::vec2 position;
    double mass;
    double r_s;
    BlackHole(glm::vec2 pos, double m);
    
    std::vector<glm::vec2> generateBlackHoleVertices(float radius, int segments) const;

};

#endif