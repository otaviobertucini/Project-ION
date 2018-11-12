#include "Moveable.h"

Moveable::Moveable()
{
    //ctor
}

Moveable::Moveable(float x, float y):Entity(x, y){}

void Moveable::setRight(bool new_mode){
    move_right = new_mode;
}

void Moveable::setLeft(bool new_mode){
    move_left = new_mode;
}

void Moveable::setUp(bool new_mode){
    move_up = new_mode;
}

void Moveable::setDown(bool new_mode){
    move_down = new_mode;
}

int Moveable::getDirection(){
    return direction;
}

Moveable::~Moveable()
{
    //dtor
}
