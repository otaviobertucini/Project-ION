#ifndef CHARACTER_H
#define CHARACTER_H
#include <allegro.h>
//#include <winalleg.h>
#include <cstddef> //library for NULL
#include <math.h>
#include <vector>
#include <iostream>
#include "Entity.h"
#include "List_Images.h"
#include "Map.h"

using std::cout;
using std::endl;

class Character: public Entity
{
public:
    Character();
    Character(float x, float y, float x_speed, float y_speed, List_Images *img);
    ~Character();
    virtual void setMap(Map* map);
    virtual void move(int x_move) = 0;
    virtual void print(BITMAP* screen) = 0;
    virtual void setPosMatrix() = 0;
    virtual void loop() = 0;
    virtual void gravity();
    void setRight(bool new_move);
    void setLeft(bool new_move);
    void setUp(bool new_move);
    void setDown(bool new_move);
protected:
    int current_side;
    float x_speed;  // Values that will be
    float y_speed;  // increased/decreased when moving.
    bool move_left;
    bool move_right;
    bool move_up;
    bool move_down;
    List_Images *img;
    Map* map;
    float y_force;
};

#endif // CHARACTER_H
