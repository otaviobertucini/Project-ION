#ifndef TUTORIAL_H
#define TUTORIAL_H
#include <Level.h>
#include "Topspin.h"
#include "Bat.h"
#include "Fireball.h"

class Tutorial: public Level
{
public:
    Tutorial();
    Tutorial(BITMAP* buffer, Images* images, Human* jack);
    int gameLoop();
    virtual void generateLevel();
    virtual ~Tutorial();
private:
    List_Powerups* powers;
};

#endif // TUTORIAL_H
