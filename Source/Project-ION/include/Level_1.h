#ifndef LEVEL_1_H
#define LEVEL_1_H
#include "Level.h"
#include "Topspin.h"
#include "Bat.h"

class Level_1: public Level
{
public:
    Level_1();
    Level_1(BITMAP* buffer, Human* jack);
    int gameLoop();
    void generateLevel();
    void generateLevel(List_Characters* characters);
    void saveLevel(std::ofstream& myfile) const;
    void loadLevel(ifstream& file);
    void printText();
    void eraseAll();
    virtual ~Level_1();
private:
    List_Fireballs* fireballs;
    double power_time;
    int start;
    List_Powerups* powers;

};

#endif // LEVEL_1_H
