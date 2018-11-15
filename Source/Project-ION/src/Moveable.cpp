#include "Moveable.h"

Moveable::Moveable()
{
    //ctor
}

Moveable::Moveable(float x, float y):Entity(x, y){}

void Moveable::setRight(const bool new_mode){
    move_right = new_mode;
}

void Moveable::setLeft(const bool new_mode){
    move_left = new_mode;
}

void Moveable::setUp(const bool new_mode){
    move_up = new_mode;
}

void Moveable::setDown(const bool new_mode){
    move_down = new_mode;
}

const int Moveable::getDirection(){
    return direction;
}

Moveable::~Moveable()
{
    //dtor
}
