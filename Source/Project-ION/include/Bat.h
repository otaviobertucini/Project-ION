#ifndef BAT_H
#define BAT_H
#include <Enemy.h>

class Bat: public Enemy
{
public:
    Bat();
    Bat(float x, float y, List_Images *img, int direction = 1, int step = 1);
    void loop();
    void move(int x_move);
    virtual ~Bat();
private:
    float flew;
    int step;
};

#endif // BAT_H
