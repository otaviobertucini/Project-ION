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
#include "List_User.h"
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
    int readLevel(ifstream& file);
    void resetLevels();
    void deleteLevels();
    void level0();
private:
    int chances;
    int i_level;
    Human* jack;
    List_user listUsers;
    User current_user;
    double power_time;
    FONT* font_main;
};

#endif // SOLOGAME_H
