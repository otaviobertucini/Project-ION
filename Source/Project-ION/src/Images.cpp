#include "Images.h"

Images::Images()
{
    //Loads images from Jack
    imgsJack = new std::vector<BITMAP*>;
    imgsJack->push_back(load_bitmap("Material/Scenario/jack_1.bmp", NULL));

    //Loads images from map
    imgsMap = new std::vector<BITMAP*>;
    imgsMap->push_back(load_bitmap("Material/Scenario/stone_1.bmp", NULL));
}

std::vector<BITMAP*>* Images::getImgsJack(){
    return imgsJack;
}

std::vector<BITMAP*>* Images::getImgsMap(){
    return imgsMap;
}

Images::~Images()
{
    std::vector<BITMAP*>::iterator itr = imgsJack->begin();
    for(itr; itr != imgsJack->end(); itr++)
        delete *itr;
    imgsJack->clear();

    std::vector<BITMAP*>::iterator itr2 = imgsMap->begin();
    for(itr2; itr2 != imgsMap->end(); itr2++)
        delete *itr2;
    imgsMap->clear();
}
