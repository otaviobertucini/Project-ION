#include "Stone.h"

Stone::Stone()
{
    //ctor
}

Stone::Stone(float x, float y, int side):
        Structure(x, y){
    List_Images* img = Images_Library::imgsMap;
    current_img = (*img)[side];
    h = 30;
    w = 30;
}

Stone::~Stone()
{
    //dtor
}
