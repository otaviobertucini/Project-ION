#include "Boss.h"

Boss::Boss(): speed(0.25)
{
    //ctor
}

Boss::Boss(float x, float y, List_Images* img, Human* jack):Enemy(x, y, img), speed(0.25){
    h = 70;
    w = 70;
    this->jack = jack;
}

void Boss::move(int x_move){

    if(x_move == -1)
        y -= speed;
    else if(x_move == 1)
        y += speed;
}

void Boss::loop(){
    //cout << "loop em andamento" << endl;

    int y_move;

    if(jack->gety() > 120 )
    {
        if(jack->gety() < y)
            y_move = -1;
        else if(jack->gety() == y)
            y_move = 0;
        else
            y_move = 1;
    }
    else
        y_move = 0;
    move(y_move);
   // move()
}

void Boss::saveState(std::ofstream& myfile) const{}

Boss::~Boss()
{
    //dtor
}
