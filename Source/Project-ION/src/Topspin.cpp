#include "Topspin.h"

Topspin::Topspin()
{
    //ctor
}

Topspin::Topspin(float x, float y, float x_speed, float y_speed, List_Images *img):
        Enemy(x, y, x_speed, y_speed, img)
{
    direction = 1;
    h = 20;
    w = 40;
}

void Topspin::move(int x_move){
    if(!move_left || !move_right){
        direction *= -1;
    }

    x += x_speed*direction;
}

void Topspin::loop(){
    //isStructureCollide();
    gravity();
    move(0);
}

Topspin::~Topspin()
{
    //dtor
}
