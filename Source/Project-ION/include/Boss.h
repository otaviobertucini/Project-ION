#ifndef BOSS_H
#define BOSS_H
#include "Enemy.h"
#include <fstream>

class Boss: public Enemy
{
public:
    Boss();
    Boss(float x, float y, List_Images* img);
    void move(int x_move);
    void loop();
    void saveState(std::ofstream& file);
    virtual ~Boss();
private:
};

#endif // BOSS_H
