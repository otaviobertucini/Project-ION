#include "Birl.h"

Birl::Birl()
{
    //ctor
}

Birl::Birl(float x, float y, BITMAP* current_img):Powerup(x, y, current_img){
    h = 30;
    w = 21;
}

void Birl::modify(Human* a){
    a->toInvincible();
}

Birl::~Birl()
{
    //dtor
}
