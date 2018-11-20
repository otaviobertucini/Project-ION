#ifndef LEVEL_6_H
#define LEVEL_6_H
#include "Level.h"
#include "Topspin.h"
#include "Bat.h"

class Level_6: public Level
{
public:
    Level_6();
    Level_6(BITMAP* buffer, Human* jack);
    int gameLoop();
    void generateLevel();
    void eraseAll();
    void saveLevel(std::ofstream& myfile) const;
    void loadLevel(ifstream& file);
    virtual ~Level_6();
private:
    List_Fireballs* fireballs;
};

#endif // LEVEL_6_H
