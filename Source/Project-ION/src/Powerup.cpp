#include "Powerup.h"

Powerup::Powerup()
{
    //ctor
}

Powerup::Powerup(float x, float y, BITMAP* current_img):Entity(x, y,  current_img){}

Powerup::~Powerup()
{
    //dtor
}
