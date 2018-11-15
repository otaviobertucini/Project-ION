#ifndef LEVEL_6_H
#define LEVEL_6_H
#include "Level.h"

class Level_6: public Level
{
public:
    Level_6();
    Level_6(BITMAP* buffer, Images* images, Human* jack);
    int gameLoop();
    void generateLevel();
    void generateLevel(List_Characters* characters);
    void resetLevel();
    void eraseAll();
    virtual ~Level_6();
private:
    List_Fireballs* fireballs;
};

#endif // LEVEL_6_H
