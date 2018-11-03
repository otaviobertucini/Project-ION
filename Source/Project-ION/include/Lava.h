#ifndef LAVA_H
#define LAVA_H
#include "Obstacle.h"

class Lava: public Obstacle
{
public:
    Lava();
    Lava(float x, float y, BITMAP* current_img);
    void setPosMatrix();
    void loop();
    virtual ~Lava();
private:
};

#endif // LAVA_H
