#ifndef OBSTACLE_H
#define OBSTACLE_H
#include "Entity.h"

class Obstacle: public Entity
{
public:
    Obstacle();
    Obstacle(float x, float y, BITMAP* current_img);
    virtual void setPosMatrix();
    virtual void loop();
    virtual ~Obstacle();
protected:
};

#endif // OBSTACLE_H
