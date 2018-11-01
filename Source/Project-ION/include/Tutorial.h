#ifndef TUTORIAL_H
#define TUTORIAL_H
#include <Level.h>
#include "Topspin.h"

class Tutorial: public Level
{
public:
    Tutorial();
    Tutorial(BITMAP* buffer, Images* images, Human* jack);
    int gameLoop();
    void generateLevel();
    void resetLevel();
    virtual ~Tutorial();
private:
};

#endif // TUTORIAL_H
