#ifndef LEVEL_5_H
#define LEVEL_5_H
#include "Level.h"
#include "Topspin.h"
#include "Bat.h"

class Level_5: public Level
{
public:
    Level_5();
    Level_5(BITMAP* buffer, Human* jack);
    int gameLoop();
    void generateLevel();
    void eraseAll();
    void saveLevel(std::ofstream& myfile) const;
    void loadLevel(ifstream& file);
    void printText();
    virtual ~Level_5();
private:
    List_Fireballs* fireballs;
    List_Powerups* powers;
    double power_time;
    int start;
};

#endif // LEVEL_5_H
