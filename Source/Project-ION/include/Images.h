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
    List_Images* getImgsBoss();
    List_Images* getImgsHandle();
    static List_Images* imgsJack;
    static List_Images *imgsMap;
    static List_Images *imgsTopspin;
    static List_Images *imgsFireball;
    static List_Images *imgsBat;
    static List_Images *imgsBoss;
    static List_Images *imgsHandle;
};

#endif // IMAGES_H
