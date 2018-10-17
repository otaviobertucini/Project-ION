#ifndef GAME_H
#define GAME_H
#include <allegro.h>
#include <stdlib.h>
#include <time.h>
#include <cstddef> //library for NULL
#include <iostream>
#include <vector>
#include "Images.h"
#include "Level.h"
#include "Map.h"

class Game
{
public:
    Game();
    virtual ~Game();
    virtual void execute() = 0;
protected:
    std::vector<Level*> levels;
    std::vector<Map*> maps;
    BITMAP* buffer;
    Images *images;
    Level *current;
};

#endif // GAME_H
