#ifndef OBSTACLE_H
#define OBSTACLE_H
#include "Entity.h"

class Obstacle: public Entity
{
public:
    Obstacle();
    Obstacle(float x, float y);
    virtual ~Obstacle();
protected:
};

#endif // OBSTACLE_H
