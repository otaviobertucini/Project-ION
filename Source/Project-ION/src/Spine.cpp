#include "Spine.h"

Spine::Spine()
{
    //ctor
}

Spine::Spine(float x, float y, int side):Obstacle(x, y){
    List_Images* img = Images::imgsMap;
    current_img = (*img)[side];
    h = 30;
    w = 30;
}

Spine::~Spine()
{
    //dtor
}
