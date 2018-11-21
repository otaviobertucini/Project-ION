#ifndef ENEMY_H
#define ENEMY_H
#include "List_Images.h"
#include "Character.h"

class Enemy: public Character
{
public:
    Enemy();
    Enemy(float x, float y);
    virtual void loop() = 0;
    virtual void move(int x_move) = 0;
    virtual ~Enemy();
protected:
};

#endif // ENEMY_H
