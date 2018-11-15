#ifndef MOVEABLE_H
#define MOVEABLE_H
#include "Entity.h"

class Moveable: public Entity
{
public:
    Moveable();
    Moveable(float x, float y);
    void setRight(const bool new_move);
    void setLeft(const bool new_move);
    void setUp(const bool new_move);
    void setDown(const bool new_move);
    const int getDirection();
    virtual void move(int x_move) = 0;
    virtual void loop() = 0;
    virtual void saveState(std::ofstream& myfile) const = 0;
    virtual ~Moveable();
protected:
    bool move_left;
    bool move_right;
    bool move_up;
    bool move_down;
    int direction;
};

#endif // MOVEABLE_H
