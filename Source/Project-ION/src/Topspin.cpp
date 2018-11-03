#include "Topspin.h"

Topspin::Topspin()
{
    //ctor
}

Topspin::Topspin(float x, float y, List_Images *img, int direction):
        Enemy(x, y, img)
{
    this->direction = direction;
    h = 20;
    w = 40;
    type = "TOP";
    x_speed = 0.2;
    y_speed = 0.06;
}

void Topspin::move(int x_move){
    if(!move_left || !move_right){
        direction *= -1;
    }

    x += x_speed*direction;
}

void Topspin::loop(){
    gravity();
    move(0);
}

Topspin::~Topspin()
{
    //dtor
}
