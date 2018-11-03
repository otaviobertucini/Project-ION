#include "Lava.h"

Lava::Lava()
{
    //ctor
}

Lava::Lava(float x, float y, BITMAP* current_img):Obstacle(x, y, current_img){
    w = 30;
    h = 30;
}

void Lava::setPosMatrix(){}

void Lava::loop(){}

Lava::~Lava()
{
    //dtor
}
