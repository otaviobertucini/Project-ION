#ifndef SPINE_H
#define SPINE_H

#include <Obstacle.h>


class Spine : public Obstacle
{
public:
    Spine();
    Spine(float x, float y, int side);
    virtual ~Spine();
private:
};

#endif // SPINE_H
