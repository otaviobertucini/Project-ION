#ifndef BOSS_H
#define BOSS_H
#include "Enemy.h"
#include "Human.h"
#include "List_Poisons.h"
#include "Poison.h"
#include <fstream>
#include <ctime>

class Boss: public Enemy
{
public:
    Boss();
    Boss(float x, float y, List_Images* img, Human* jack);
    void move(int x_move);
    void loop();
    void saveState(std::ofstream& file) const;
    void createPoison(List_Poisons* poisons);
    void verifyDirection();
    virtual ~Boss();
private:
    Human* jack;
    const float speed;
    int side_ball;
    double timer;
    int last_poison;
};

#endif // BOSS_H
