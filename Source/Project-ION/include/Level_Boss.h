#ifndef LEVEL_BOSS_H
#define LEVEL_BOSS_H
#include "Level.h"

class Level_Boss: public Level
{
public:
    Level_Boss();
    Level_Boss(BITMAP* buffer, Images* images, Human* jack);
    int gameLoop();
    void generateLevel();
    void generateLevel(List_Characters* characters);
    void startLevel();
    void resetLevel();
    virtual ~Level_Boss();
private:
};

#endif // LEVEL_Boss_H
