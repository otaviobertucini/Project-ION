#ifndef LEVEL_BOSS_H
#define LEVEL_BOSS_H
#include "Level.h"
#include "Level_Boss.h"
#include "Boss.h"
#include "List_Poisons.h"
#include "Handle.h"
#include "List_Handles.h"

class Level_Boss: public Level
{
public:
    Level_Boss();
    Level_Boss(BITMAP* buffer, Images* images, Human* jack);
    int gameLoop();
    void generateLevel();
    void generateLevel(List_Characters* characters);
    void saveLevel(std::ofstream& myfile) const;
    void loadLevel(ifstream& file);
    void eraseAll();
    virtual ~Level_Boss();
private:
    Boss* boss;
    List_Poisons* poisons;
    List_Handles* handles;
};

#endif // LEVEL_Boss_H
