#ifndef TOPSPIN_H
#define TOPSPIN_H
#include "Enemy.h"

class Topspin: public Enemy
{
public:
    Topspin();
    Topspin(float x, float y, List_Images *img, int direction = 1);
    void move(int x_move);
    void loop();
    void saveState(std::ofstream& myfile);
    virtual ~Topspin();
private:
};

#endif // TOPSPIN_H
