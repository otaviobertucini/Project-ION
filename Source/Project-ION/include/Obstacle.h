#ifndef OBSTACLE_H
#define OBSTACLE_H
#include "Entity.h"

class Obstacle: public Entity
{
public:
    Obstacle();
    Obstacle(float x, float y, BITMAP* current_img);
    virtual void setPosMatrix() = 0;
    virtual void loop() = 0;
    virtual ~Obstacle();
protected:
};

#endif // OBSTACLE_H
