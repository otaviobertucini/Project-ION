#ifndef LEVEL_2_H
#define LEVEL_2_H
#include "Level.h"
#include "Topspin.h"
#include "Bat.h"
class Level_2: public Level
{
public:
    Level_2();
    Level_2(BITMAP* buffer, Human* jack);
    int gameLoop();
    void generateLevel();
    void generateLevel(List_Characters* characters);
    void eraseAll();
    void printText();
    void saveLevel(std::ofstream& myfile) const;
    void loadLevel(ifstream& file);
    virtual ~Level_2();
private:
    List_Powerups* powers;
    double power_time;
    int start;
    List_Fireballs* fireballs;
};

#endif // LEVEL_2_H
