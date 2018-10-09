#ifndef LEVEL_H
#define LEVEL_H
#include <allegro.h>
#include <cstddef> //library for NULL
#include "Map.h"
#include <iostream>
using std::cout;
using std::endl;

class Level
{
public:
    Level();
    Level(BITMAP* screen);
    ~Level();
    void setMap(Map* map);
    Map* getMap();
    int printMap();
private:
    Map* map;
    BITMAP* screen;
};

#endif // LEVEL_H
