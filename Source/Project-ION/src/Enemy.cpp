#include "Enemy.h"

Enemy::Enemy()
{
    //ctor
}

Enemy::Enemy(float x, float y, List_Images *img):
        Character(x, y, img)
{}

void Enemy::setPosMatrix(){}

Enemy::~Enemy()
{
    //dtor
}
