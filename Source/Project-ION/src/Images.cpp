#include "Images.h"

Images::Images()
{
    //Loads images from Jack
    imgsJack = new List_Images;
    imgsJack->include(load_bitmap("Material/Scenario/jack_1.bmp", NULL));

    //Loads images from map
    imgsMap = new List_Images;
    imgsMap->include(load_bitmap("Material/Scenario/stone_1.bmp", NULL));
}

List_Images* Images::getImgsJack(){
    return imgsJack;
}

List_Images* Images::getImgsMap(){
    return imgsMap;
}

Images::~Images()
{
    imgsJack->deleteAll();
    imgsMap->deleteAll();
}
