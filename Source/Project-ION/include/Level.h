#ifndef LEVEL_H
#define LEVEL_H
#include <allegro.h>
#include <cstddef> //library for NULL
#include <iostream>
#include <vector>
#include "Map.h"
#include "Character.h"
#include "Human.h"
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
    void updatePosition();
    Human* getJack();
    int getValueMap(int i, int j);
private:
    Map* map;
    BITMAP* screen;
    std::vector<Character*> characters;
    Human* jack;
};

#endif // LEVEL_H
