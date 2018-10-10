#include "Character.h"

Character::Character()
{
    //ctor
}

Character::Character(int x, int y, int x_speed, int y_speed, std::vector<BITMAP*> *img){
    this->x = x;
    this->y = y;
    this->x_speed = x_speed;
    this->y_speed = y_speed;
    this->img = img;
}

Character::~Character()
{
    /*std::vector<BITMAP*>::iterator itr = img->begin();
    for(itr; itr != img->end(); itr++)
        delete *itr;
    img->clear();*/
}
