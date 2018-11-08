#include "Spine.h"

Spine::Spine()
{
    //ctor
}

Spine::Spine(float x, float y, BITMAP* current_img):Obstacle(x, y, current_img){
    h = 30;
    w = 30;
}

Spine::~Spine()
{
    //dtor
}
