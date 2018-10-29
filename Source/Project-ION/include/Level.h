#ifndef LEVEL_H
#define LEVEL_H
#include <allegro.h>
#include <cstddef> //library for NULL
#include <iostream>
#include <vector>
#include "Map.h"
#include "Character.h"
#include "Human.h"
#include "List_Images.h"
using std::cout;
using std::endl;

class Level
{
public:
    Level();
    Level(BITMAP* buffer, List_Images *img);
    ~Level();
    void setMap(Map* map);
    Map* getMap();
    int printMap();
    void updatePosition();
    Human* getJack();
    int getValueMap(int i, int j);
private:
    Map* map; //Pointer to the level map.
    BITMAP* buffer; //Pointer to the display where all components will be shown.
};

#endif // LEVEL_H
