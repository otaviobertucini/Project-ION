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
using std::cout;
using std::endl;

class SoloGame: public Game
{
public:
    SoloGame();
    ~SoloGame();
    void execute();
    void level0();
private:
    Human *jack;
};

#endif // SOLOGAME_H
