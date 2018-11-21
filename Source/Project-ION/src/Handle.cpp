#include "Handle.h"

Handle::Handle()
{
    //ctor
}

int Handle::switched_on = 0;

Handle::Handle(float x, float y, bool on):Structure(x, y){
    h = 30;
    w = 30;
    List_Images* img = Images_Library::imgsHandle;
    current_img = (*img)[on];
    this->on = on;
}

void Handle::switch_on(){
    if(!on){
        List_Images* img = Images_Library::imgsHandle;
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
