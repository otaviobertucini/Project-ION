#include "Boss.h"

Boss::Boss()
{
    //ctor
}

Boss::Boss(float x, float y, List_Images* img):Enemy(x, y, img){
    h = 70;
    w = 70;
}

void Boss::move(int x_move){
    cout << "estou me movendo" << endl;
}

void Boss::loop(){
    //cout << "loop em andamento" << endl;
}

void Boss::saveState(std::ofstream& myfile){}

Boss::~Boss()
{
    //dtor
}
