#ifndef LEVEL_4_1_H
#define LEVEL_4_1_H
#include "Level.h"
#include "Topspin.h"
#include "Bat.h"

class Level_4_1: public Level
{
public:
    Level_4_1();
    Level_4_1(BITMAP* buffer, Human* jack);
    int gameLoop();
    void generateLevel();
    void generateLevel(List_Characters* characters);
    void resetLevel();
    virtual ~Level_4_1();
private:
};

#endif // LEVEL_4_1_H
