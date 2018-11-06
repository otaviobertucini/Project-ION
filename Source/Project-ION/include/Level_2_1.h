#ifndef LEVEL_2_1_H
#define LEVEL_2_1_H
#include "Level.h"

class Level_2_1: public Level
{
public:
    Level_2_1();
    Level_2_1(BITMAP* buffer, Images* images, Human* jack);
    int gameLoop();
    void generateLevel();
    void generateLevel(List_Characters* characters);
    void startLevel();
    void resetLevel();
    virtual ~Level_2_1();
private:
};

#endif // LEVEL_2_1_H
