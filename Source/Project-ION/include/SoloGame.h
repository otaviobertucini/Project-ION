#ifndef SOLOGAME_H
#define SOLOGAME_H
#include <allegro.h>
//#include <winalleg.h>
#include <stdlib.h>
#include <time.h>
#include <cstddef> //library for NULL
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Human.h"
#include "Game.h"
#include "Topspin.h"
#include "Tutorial.h"
#include "Level_1.h"
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
    void saveLevel();
    void readLevel(List_Characters* characters);
    void startLevels();
    void resetLevels();
    void level0();
private:
    Menu* menu1;
    int chances;
    int i_level;
    Human* jack;
};

#endif // SOLOGAME_H
