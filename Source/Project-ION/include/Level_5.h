#ifndef LEVEL_5_H
#define LEVEL_5_H
#include "Level.h"
#include "Topspin.h"
#include "Bat.h"

class Level_5: public Level
{
public:
    Level_5();
    Level_5(BITMAP* buffer, Images* images, Human* jack);
    int gameLoop();
    void generateLevel();
    void eraseAll();
    void saveLevel(std::ofstream& myfile) const;
    void loadLevel(ifstream& file);
    virtual ~Level_5();
private:
    List_Fireballs* fireballs;
};

#endif // LEVEL_5_H
