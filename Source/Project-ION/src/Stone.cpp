#include "Stone.h"

Stone::Stone()
{
    //ctor
}

Stone::Stone(float x, float y, BITMAP* current_img):
        Structure(x, y, current_img){}

void Stone::loop(){}

Stone::~Stone()
{
    //dtor
}
