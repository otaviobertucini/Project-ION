#include "Handle.h"

Handle::Handle()
{
    //ctor
}

int Handle::switched_on = 0;

Handle::Handle(float x, float y, List_Images* img, bool on):Structure(x, y, NULL){
    h = 30;
    w = 30;
    this->img = img;
    current_img = (*img)[on];
    this->on = on;
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

void Handle::setSwitchedOn(const int n){
    switched_on = n;
}

void Handle::saveState(std::ofstream& myfile) const{
    myfile << "HAN:" << x << "," << y << "," << on << "\n";
}

Handle::~Handle()
{
    //dtor
}
