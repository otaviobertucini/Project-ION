#include "Bat.h"

Bat::Bat()
{
    //ctor
}

Bat::Bat(float x, float y, List_Images *img):Enemy(x, y, img){
    type = "BAT";
    h = 30;
    w = 40;
    vertical = true;
    dir_vertical = 1;
    dir_horizontal = -1;
    flew = 0.0;
}

void Bat::move(int x_move){
    if(vertical){
        y += 0.2*dir_vertical;
        flew += 0.2;
        if(flew > 30){
            vertical = false;
            dir_vertical *= -1;
            flew = 0.0;
        }
    }
    else{
        x += 0.2*direction;
        flew += 0.2;
        if(flew > 60){
            vertical = true;
            direction *= -1;
            flew = 0.0;
        }
    }
}

void Bat::loop(){
    move(0);
}

Bat::~Bat()
{
    //dtor
}
