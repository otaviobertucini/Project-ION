#ifndef LEVEL_5_H
#define LEVEL_5_H
#include "Level.h"

class Level_5: public Level
{
public:
    Level_5();
    Level_5(BITMAP* buffer, Images* images, Human* jack);
    int gameLoop();
    void generateLevel();
    void generateLevel(List_Characters* characters);
    void startLevel();
    void resetLevel();
    virtual ~Level_5();
private:
};

#endif // LEVEL_5_H
