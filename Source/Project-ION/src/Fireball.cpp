#include "Fireball.h"

Fireball::Fireball()
{
    //ctor
}

Fireball::Fireball(float x, float y):Moveable(x, y){
    List_Images* imgs = Images::imgsFireball;
    current_img =(*imgs)[0];
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

const bool Fireball::getMoveUp() const{
    return move_up;
}

void Fireball::saveState(std::ofstream& myfile) const{
    myfile << "FIR:" << x << "," << y << "\n";
}

Fireball::~Fireball()
{}
