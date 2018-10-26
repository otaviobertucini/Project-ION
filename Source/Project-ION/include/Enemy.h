#ifndef ENEMY_H
#define ENEMY_H
#include "Character.h"
#include "List_Images.h"

class Enemy: public Character
{
public:
    Enemy();
    Enemy(float x, float y, float x_speed, float y_speed, List_Images *img);
    void setPosMatrix();
    virtual void move(int x_move) = 0;
    void print(BITMAP* screen);
    virtual ~Enemy();
protected:


};

#endif // ENEMY_H
