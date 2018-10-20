#ifndef IMAGES_H
#define IMAGES_H
#include <allegro.h>
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
private:
    List_Images *imgsJack;
    List_Images *imgsMap;
};

#endif // IMAGES_H
