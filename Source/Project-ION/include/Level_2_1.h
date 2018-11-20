#ifndef LEVEL_2_1_H
#define LEVEL_2_1_H
#include "Level.h"
#include "Topspin.h"
#include "Bat.h"

class Level_2_1: public Level
{
public:
    Level_2_1();
    Level_2_1(BITMAP* buffer, Human* jack);
    int gameLoop();
    void generateLevel();
    void generateLevel(List_Characters* characters);
    void resetLevel();
    virtual ~Level_2_1();
private:
};

#endif // LEVEL_2_1_H
