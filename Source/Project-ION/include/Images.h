#ifndef IMAGES_H
#define IMAGES_H
#include <allegro.h>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <cstddef> //library for NULL
using std::cout;
using std::endl;

class Images
{
public:
    Images();
    ~Images();
    std::vector<BITMAP*>* getImgsJack();
    std::vector<BITMAP*>* getImgsMap();
private:
    std::vector<BITMAP*> *imgsJack;
    std::vector<BITMAP*> *imgsMap;
};

#endif // IMAGES_H
