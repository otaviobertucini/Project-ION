#include "Structure.h"

Structure::Structure()
{
    //ctor
}

Structure::Structure(float x, float y, BITMAP* current_img):
            Entity(x, y, current_img)
{
    setPosMatrix();
}

void Structure::setPosMatrix(){
    i_pos = (int)floor(y/30);
    j_pos = (int)floor(x/30);
}

Structure::~Structure()
{
    //dtor
}
