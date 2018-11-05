#ifndef FIREBALL_H
#define FIREBALL_H
#include "List_Images.h"
#include <Enemy.h>

class Fireball : public Enemy
{
public:
    Fireball();
    Fireball(float x, float y, BITMAP* img);
    void move(int x_move);
    void loop();
    bool getMoveUp();
    virtual ~Fireball();
private:
};

#endif // FIREBALL_H
