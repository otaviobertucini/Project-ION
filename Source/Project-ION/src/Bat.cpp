#include "Bat.h"

Bat::Bat()
{
    //ctor
}

Bat::Bat(float x, float y, List_Images *img, int direction, int step, int x_distance, int y_distance):Enemy(x, y, img){
    type = "BAT";
    h = 30;
    w = 40;
    flew = 0.0;
    this->direction = direction;
    this->step = step;
    this->x_distance = x_distance;
    this->y_distance = y_distance;
}

void Bat::move(int x_move){
    //cout << step << endl;
    if(step == 1)
    {
        y += 0.2;
        flew += 0.2;
        if(flew > y_distance)
        {
            flew = 0.0;
            step = 2;
        }
    }
    else if(step == 2)
    {
       // cout << flew << endl;
        x += 0.2*direction;
        flew += 0.2;
        if(flew > x_distance)
        {
            direction *= -1;
            step = 3;
            flew = 0.0;
        }
    }
    else if(step = 3){
        y -= 0.2;
        flew += 0.2;
        if(flew > y_distance)
        {
            flew = 0.0;
            step = 1;
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
