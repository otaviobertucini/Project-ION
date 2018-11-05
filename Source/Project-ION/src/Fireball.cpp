#include "Fireball.h"

Fireball::Fireball()
{
    //ctor
}

Fireball::Fireball(float x, float y, BITMAP* img):Enemy(x, y, NULL){
    this->current_img = img;
    h = 10;
    w = 10;
}

void Fireball::move(int x_move){
    if(move_up){
        y -= 0.1;
    }
}

void Fireball::loop(){
    move(0);
}

bool Fireball::getMoveUp(){
    return move_up;
}

Fireball::~Fireball()
{
    //dtor
}
