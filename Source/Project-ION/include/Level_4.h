#ifndef LEVEL_4_H
#define LEVEL_4_H
#include "Level.h"
#include "Topspin.h"
#include "Bat.h"

class Level_4: public Level
{
public:
    Level_4();
    Level_4(BITMAP* buffer, Human* jack);
    int gameLoop();
    void generateLevel();
    virtual ~Level_4();
private:
};

#endif // LEVEL_4_H
