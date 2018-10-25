#include "Enemy.h"

Enemy::Enemy()
{
    //ctor
}

Enemy::Enemy(float x, float y, float x_speed, float y_speed, List_Images *img):
        Character(x, y, x_speed, y_speed, img)
{}

Enemy::~Enemy()
{
    //dtor
}
