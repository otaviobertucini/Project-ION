#ifndef LEVEL_1_H
#define LEVEL_1_H
#include "Level.h"
#include "Topspin.h"
#include "Bat.h"

class Level_1: public Level
{
public:
    Level_1();
    Level_1(BITMAP* buffer, Images* images, Human* jack);
    int gameLoop();
    void generateLevel();
    void generateLevel(List_Characters* characters);
    void saveLevel(std::ofstream& myfile) const;
    void loadLevel(ifstream& file);
    void eraseAll();
    virtual ~Level_1();
private:
    List_Fireballs* fireballs;
};

#endif // LEVEL_1_H
