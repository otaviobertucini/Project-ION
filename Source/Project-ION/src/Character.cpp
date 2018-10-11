#include "Character.h"

Character::Character()
{
    //ctor
}

Character::Character(float x, float y, float x_speed, float y_speed, std::vector<BITMAP*> *img){
    this->x = x;
    this->y = y;
    this->x_speed = x_speed;
    this->y_speed = y_speed;
    this->img = img;
}

void Character::getPosMatrix(int *i, int *j){
    *j = (int)floor((y+60)/30);
    *i = (int)floor((x+40)/30)-1;
}

Character::~Character()
{
    /*std::vector<BITMAP*>::iterator itr = img->begin();
    for(itr; itr != img->end(); itr++)
        delete *itr;
    img->clear();*/
}
