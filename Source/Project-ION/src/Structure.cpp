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

void Structure::print(BITMAP* screen){
    blit(current_img, screen, 0, 0, x, y, 40, 60);
}

Structure::~Structure()
{
    //dtor
}
