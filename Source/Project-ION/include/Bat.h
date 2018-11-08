#ifndef BAT_H
#define BAT_H
#include <Enemy.h>

class Bat: public Enemy
{
public:
    Bat();
    Bat(float x, float y, List_Images *img);
    void loop();
    void move(int x_move);
    virtual ~Bat();
private:
    bool vertical;
    int dir_vertical;
    int dir_horizontal;
    float flew;
};

#endif // BAT_H
