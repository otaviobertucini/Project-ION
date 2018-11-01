#ifndef LEVEL_1_H
#define LEVEL_1_H
#include "Level.h"

class Level_1: public Level
{
public:
    Level_1();
    Level_1(BITMAP* buffer, Images* images, Human* jack);
    int gameLoop();
    void generateLevel();
    void resetLevel();
    virtual ~Level_1();
private:
};

#endif // LEVEL_1_H
