#ifndef IMAGES_H
#define IMAGES_H
#include <allegro.h>
//#include <winalleg.h>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <cstddef> //library for NULL
#include "List_Images.h"
using std::cout;
using std::endl;

class Images
{
public:
    Images();
    ~Images();
    List_Images* getImgsJack();
    List_Images* getImgsMap();
    List_Images* getImgsTopspin();
    List_Images* getImgsLava();
    List_Images* getImgsFireball();
    List_Images* getImgsBat();
private:
    List_Images *imgsJack;
    List_Images *imgsMap;
    List_Images *imgsTopspin;
    List_Images *imgsFireball;
    List_Images *imgsBat;
};

#endif // IMAGES_H
