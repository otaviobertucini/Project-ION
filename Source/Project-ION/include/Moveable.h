#ifndef MOVEABLE_H
#define MOVEABLE_H
#include "Entity.h"

class Moveable: public Entity
{
public:
    Moveable();
    Moveable(float x, float y);
    void setRight(bool new_move);
    void setLeft(bool new_move);
    void setUp(bool new_move);
    void setDown(bool new_move);
    int getDirection();
    virtual ~Moveable();
protected:
    bool move_left;
    bool move_right;
    bool move_up;
    bool move_down;
    int direction;
};

#endif // MOVEABLE_H
