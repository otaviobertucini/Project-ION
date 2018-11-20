#ifndef GAME_H
#define GAME_H
#include <allegro.h>
//#include <winalleg.h>
#include <stdlib.h>
#include <time.h>
#include <cstddef> //library for NULL
#include <iostream>
#include<stdlib.h>
#include <vector>
#include "Images.h"
#include "Level.h"
#include "List_Levels.h"
#include "Menu.h"


class Game
{
public:
    Game();
    virtual ~Game();
    virtual void execute() = 0;
protected:
    List_Levels* levels;
    BITMAP* buffer;
    Images_Library *images;
    Level *current;
    Menu* menu1;
};

#endif // GAME_H
