#ifndef LEVEL_2_H
#define LEVEL_2_H
#include "Level.h"

class Level_2: public Level
{
public:
    Level_2();
    Level_2(BITMAP* buffer, Images* images, Human* jack);
    int gameLoop();
    void generateLevel();
    void generateLevel(List_Characters* characters);
    void startLevel();
    void resetLevel();
    virtual ~Level_2();
private:
};

#endif // LEVEL_2_H
