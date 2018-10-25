#include "Character.h"

Character::Character()
{
    //ctor
}

Character::Character(float x, float y, float x_speed, float y_speed, List_Images *img):
            Entity(x, y)
{
    this->x_speed = x_speed;
    this->y_speed = y_speed;
    this->img = img;
    this->map = NULL;
    this->move_left = true;
    this->move_right = true;
    this->move_up = true;
    this->move_down = true;
}

Character::~Character()
{
    img->deleteAll();
}

void Character::setMap(Map* mp)
{
        map = mp;
}
