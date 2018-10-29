#ifndef TOPSPIN_H
#define TOPSPIN_H
#include "Enemy.h"

class Topspin: public Enemy
{
public:
    Topspin();
    Topspin(float x, float y, float x_speed, float y_speed, List_Images *img);
    void move(int x_move);
    void loop();
    virtual ~Topspin();
private:
    int direction;
};

#endif // TOPSPIN_H
