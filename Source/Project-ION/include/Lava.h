#ifndef LAVA_H
#define LAVA_H
#include "time.h"
#include "Obstacle.h"
#include "Fireball.h"

class Lava: public Obstacle
{
public:
    Lava();
    Lava(float x, float y, BITMAP* current_img);
    void setPosMatrix();
    void loop();
    Fireball* createFireball();
    virtual ~Lava();
private:
};

#endif // LAVA_H
