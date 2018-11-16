#include "Handle.h"

Handle::Handle()
{
    //ctor
}

int Handle::switched_on = 0;

Handle::Handle(float x, float y, List_Images* img):Structure(x, y, NULL){
    h = 30;
    w = 30;
    this->img = img;
    current_img = (*img)[0];
    on = false;
}

void Handle::switch_on(){
    if(!on){
        on = true;
        switched_on++;
        current_img = (*img)[1];
    }
}

int Handle::getSwitchedOn(){
    return switched_on;
}

Handle::~Handle()
{
    //dtor
}
