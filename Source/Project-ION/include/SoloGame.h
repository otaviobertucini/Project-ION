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
#include <ctime>
#include "Human.h"
#include "User.h"
#include "Game.h"
#include "Topspin.h"
#include "Tutorial.h"
#include "Level_1.h"
#include "Level_2.h"
#include "Level_2_1.h"
#include "Level_3.h"
#include "Level_4.h"
#include "Level_4_1.h"
#include "Level_5.h"
#include "Level_6.h"
#include "Level_Boss.h"

using std::cout;
using std::endl;

class SoloGame: public Game
{
public:
    SoloGame();
    SoloGame(Menu* menu, BITMAP* buffer);
    ~SoloGame();
    void menu();
    void execute();
    void saveLevel();
    //void readLevel(List_Characters* characters, List_Powerups* powers, List_Fireballs* fires);
    int readLevel(ifstream& file);
    void resetLevels();
    void deleteLevels();
    void level0();
private:
    int chances;
    int i_level;
    Human* jack;
    User usuario;
    double power_time;
};

#endif // SOLOGAME_H
