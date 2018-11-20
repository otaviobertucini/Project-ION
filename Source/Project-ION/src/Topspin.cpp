#include "Topspin.h"

Topspin::Topspin()
{
    //ctor
}

Topspin::Topspin(float x, float y, int direction):
        Enemy(x, y)
{
    this->direction = direction;
    h = 20;
    w = 40;
    type = "TOP";
    x_speed = 0.2;
    y_speed = 0.06;
    List_Images* img = Images::imgsTopspin;
    current_img = (*img)[1];
}

void Topspin::move(int x_move){
    List_Images* img = Images::imgsTopspin;
    if(!move_left){
        direction = 1;
        current_img = (*img)[1];
        move_left = true;
    }
    else if(!move_right){
        direction = -1;
        current_img = (*img)[0];
        move_right = true;
    }

    x += x_speed*direction;
}

void Topspin::loop(){
    gravity();
    move(0);
}

void Topspin::saveState(std::ofstream& myfile) const{
    myfile << type << ":" << x << "," << y << "," << direction << "\n";
}

Topspin::~Topspin()
{
    //dtor
}
