#ifndef SOLOGAME_H
#define SOLOGAME_H
#include <allegro.h>
//#include <winalleg.h>
#include <stdlib.h>
#include <time.h>
#include <cstddef> //library for NULL
#include <iostream>
#include <vector>
#include "Human.h"
#include "Game.h"
#include "Topspin.h"
#include "Tutorial.h"
#include "Menu.h"

using std::cout;
using std::endl;

class SoloGame: public Game
{
public:
    SoloGame();
    ~SoloGame();
    void menu();
    void execute();
    void level0();
private:
    Menu* menu1;
    int chances;
};

#endif // SOLOGAME_H
