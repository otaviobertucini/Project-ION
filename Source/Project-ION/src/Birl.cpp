#include "Birl.h"

Birl::Birl()
{
    //ctor
}

Birl::Birl(float x, float y):Powerup(x, y){
    h = 30;
    w = 21;
    type = "BIL";
}

void Birl::modify(Human* a){
    a->turnPowerup();
}

Birl::~Birl()
{
    //dtor
}
