#include "Fireball.h"

Fireball::Fireball()
{
    //ctor
}

Fireball::Fireball(float x, float y, BITMAP* img):Moveable(x, y){
    this->current_img = img;
    h = 10;
    w = 10;
}

void Fireball::move(int x_move){
    if(move_up){
        y -= 0.2;
    }
}

void Fireball::loop(){
    move(0);
}

bool Fireball::getMoveUp(){
    return move_up;
}

void Fireball::saveState(std::ofstream& myfile){
    myfile << "FIR:" << x << "," << y << "\n";
}

void Fireball::setPosMatrix(){}

Fireball::~Fireball()
{
}
