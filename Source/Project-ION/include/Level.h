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
    Level(BITMAP* buffer);
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
    std::vector<Character*> characters; //Vector of ALL characters in the level.
};

#endif // LEVEL_H
