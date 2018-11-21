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
    Tutorial(BITMAP* buffer, Human* jack);
    int gameLoop();
    virtual void generateLevel();
    void eraseAll();
    void printText();
    virtual ~Tutorial();
private:
    double power_time;
    int start;
};

#endif // TUTORIAL_H
