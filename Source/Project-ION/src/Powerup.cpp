#include "Powerup.h"

Powerup::Powerup()
{
    //ctor
}

Powerup::Powerup(float x, float y):Entity(x, y){
    List_Images* img = Images::imgsMap;
    current_img = (*img)[23];
}

Powerup::~Powerup()
{
    //dtor
}
