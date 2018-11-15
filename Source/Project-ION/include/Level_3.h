#ifndef LEVEL_3_H
#define LEVEL_3_H
#include "Level.h"
#include "Topspin.h"
#include "Bat.h"

class Level_3: public Level
{
public:
    Level_3();
    Level_3(BITMAP* buffer, Images* images, Human* jack);
    int gameLoop();
    void generateLevel();
    void generateLevel(List_Characters* characters);
    void resetLevel();
    virtual ~Level_3();
private:
    List_Fireballs* fireballs;
};

#endif // LEVEL_3_H
