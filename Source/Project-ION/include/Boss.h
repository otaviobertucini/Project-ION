#ifndef BOSS_H
#define BOSS_H
#include "Enemy.h"
#include "Human.h"
#include <fstream>

class Boss: public Enemy
{
public:
    Boss();
    Boss(float x, float y, List_Images* img, Human* jack);
    void move(int x_move);
    void loop();
    void saveState(std::ofstream& file) const;
    virtual ~Boss();
private:
    Human* jack;
    const float speed;
};

#endif // BOSS_H
