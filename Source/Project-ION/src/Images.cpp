#include "Images.h"

Images::Images()
{
    //Loads images from Jack
    imgsJack = new std::vector<BITMAP*>;
    imgsJack->push_back(load_bitmap("/home/otavio/Documentos/Project_ION/Material/Scenario/jack_1.bmp", NULL));

    //Loads images from map
    imgsMap = new std::vector<BITMAP*>;
    imgsMap->push_back(load_bitmap("/home/otavio/Documentos/Project_ION/Material/Scenario/stone_1.bmp", NULL));
}

std::vector<BITMAP*>* Images::getImgsJack(){
    return imgsJack;
}

std::vector<BITMAP*>* Images::getImgsMap(){
    return imgsMap;
}

Images::~Images()
{
    //dtor
}
