#include "Bat.h"

Bat::Bat():x_distance(0), y_distance(0)
{
    //ctor
}

Bat::Bat(float x, float y, int direction, int step, int x_distance, int y_distance, float flew)
        :Enemy(x, y), x_distance(x_distance), y_distance(y_distance){
    type = "BAT";
    h = 30;
    w = 40;
    this->flew = flew;
    this->direction = direction;
    this->step = step;
    move_animation = 0;
    confirmAnimation = true;
    List_Images* img = Images_Library::imgsBat;
    current_img = (*img)[0];
}

void Bat::move(int x_move){
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
    else if(step == 3){
        y -= 0.2;
        flew += 0.2;
        if(flew > y_distance)
        {
            flew = 0.0;
            step = 1;
        }
    }

    move_animation+=0.2;
    animationBat();
}

void Bat::animationBat()
{
    List_Images* img = Images_Library::imgsBat;
    if(move_animation > 30)
    {
        if(confirmAnimation)
        {
            current_img = (*img)[1];
            confirmAnimation = false;
        }
        else
        {
            current_img = (*img)[0];
            confirmAnimation = true;
        }
        move_animation = 0;
    }
}

void Bat::loop(){
    move(0);
}

void Bat::saveState(std::ofstream& myfile) const{
    myfile << type << ":" << x << "," << y << "," << direction << "," << step << "," <<
            y_distance << "," << x_distance << "," << flew << "\n";
}

Bat::~Bat()
{
    //dtor
}
