#include "Spine.h"

Spine::Spine()
{
    //ctor
}

Spine::Spine(float x, float y, int side):Obstacle(x, y){
    List_Images* img = Images_Library::imgsMap;
    current_img = (*img)[side];
    h = 30;
    w = 30;
}

Spine::~Spine()
{
    //dtor
}
