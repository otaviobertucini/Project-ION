#include "Bat.h"

Bat::Bat()
{
    //ctor
}

Bat::Bat(float x, float y, List_Images *img, int direction, int step, int x_distance, int y_distance, float flew)
        :Enemy(x, y, img){
    type = "BAT";
    h = 30;
    w = 40;
    this->flew = flew;
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

const int Bat::getyInitial() const{
    return y_initial + y_distance;
}

void Bat::saveState(std::ofstream& myfile){
    myfile << type << ":" << x << "," << y << "," << direction << "," << step << "," <<
            y_distance << "," << x_distance << "," << flew << "\n";
}

Bat::~Bat()
{
    //dtor
}
