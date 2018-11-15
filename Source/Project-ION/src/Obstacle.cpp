#include "Obstacle.h"

Obstacle::Obstacle()
{
    //ctor
}

Obstacle::Obstacle(float x, float y, BITMAP* current_img):Entity(x, y, current_img){}

Obstacle::~Obstacle()
{
    //dtor
}
