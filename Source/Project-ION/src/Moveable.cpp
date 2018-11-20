#include "Moveable.h"

Mover::Mover()
{
    //ctor
}

Mover::Mover(float x, float y):Entity(x, y){}

void Mover::setRight(const bool new_mode){
    move_right = new_mode;
}

void Mover::setLeft(const bool new_mode){
    move_left = new_mode;
}

void Mover::setUp(const bool new_mode){
    move_up = new_mode;
}

void Mover::setDown(const bool new_mode){
    move_down = new_mode;
}

const int Mover::getDirection(){
    return direction;
}

Mover::~Mover()
{
    //dtor
}
