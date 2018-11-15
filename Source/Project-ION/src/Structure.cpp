#include "Structure.h"

Structure::Structure()
{
    //ctor
}

Structure::Structure(float x, float y, BITMAP* current_img):
            Entity(x, y, current_img)
{}

Structure::~Structure()
{
    //dtor
}
