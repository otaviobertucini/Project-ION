#include "Character.h"

Character::Character()
{
    //ctor
}

Character::Character(float x, float y, float x_speed, float y_speed, std::vector<BITMAP*> *img):
            Entity(x, y, img)
{
    this->x_speed = x_speed;
    this->y_speed = y_speed;
}

Character::~Character()
{
    std::vector<BITMAP*>::iterator itr = img->begin();
    for(itr; itr != img->end(); itr++)
        delete *itr;
    img->clear();
}
