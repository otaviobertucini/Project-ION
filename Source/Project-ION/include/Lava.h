#ifndef LAVA_H
#define LAVA_H
#include "time.h"
#include "Obstacle.h"
#include "Fireball.h"

class Lava: public Obstacle
{
public:
    Lava();
    Lava(float x, float y, int id);
    Fireball* createFireball();
    virtual ~Lava();
private:
    List_Images* img;
};

#endif // LAVA_H
