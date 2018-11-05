#ifndef CHARACTER_H
#define CHARACTER_H
#include <allegro.h>
//#include <winalleg.h>
#include <cstddef> //library for NULL
#include <math.h>
#include <vector>
#include <iostream>
#include <string>
#include "Entity.h"
#include "List_Images.h"

using std::cout;
using std::endl;

class Character: public Entity
{
public:
    Character();
    Character(float x, float y, List_Images *img);
    ~Character();
    virtual void move(int x_move) = 0;
    virtual void setPosMatrix() = 0;
    virtual void loop() = 0;
    virtual void gravity();
    std::string getType();
    void setRight(bool new_move);
    void setLeft(bool new_move);
    void setUp(bool new_move);
    void setDown(bool new_move);
    int getDirection();
protected:
    std::string type;
    int current_side;
    float x_speed;  // Values that will be
    float y_speed;  // increased/decreased when moving.
    bool move_left;
    bool move_right;
    bool move_up;
    bool move_down;
    List_Images *img;
    float y_force;
    int direction;
};

#endif // CHARACTER_H
