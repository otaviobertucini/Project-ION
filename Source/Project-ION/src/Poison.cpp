#include "Poison.h"

Poison::Poison()
{
    //ctor
}

Poison::Poison(float x, float y, BITMAP* current_img, int direction):Moveable(x, y){
    this->current_img = current_img;
    h = 25;
    w = 25;
    this->direction = direction;
}

void Poison::loop(){
    move(0);
}

void Poison::move(int x_move){
    x += -0.2*direction;
}

void Poison::saveState(std::ofstream& file) const{}

const bool Poison::getMoveSide() const{
    if(!move_right || !move_left){
        return false;
    }
    return true;
}

Poison::~Poison()
{
    destroy_bitmap(current_img);
}
