#include "Enemy.h"

Enemy::Enemy()
{
    //ctor
}

Enemy::Enemy(float x, float y, List_Images *img):
        Character(x, y, img)
{}

Enemy::~Enemy()
{
    //dtor
}
