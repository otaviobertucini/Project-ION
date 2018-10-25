#ifndef ENEMY_H
#define ENEMY_H
#include "Character.h"
#include "List_Images.h"

class Enemy: public Character
{
public:
    Enemy();
    Enemy(float x, float y, float x_speed, float y_speed, List_Images *img);
    virtual ~Enemy();
protected:

};

#endif // ENEMY_H
