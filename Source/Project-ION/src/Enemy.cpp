#include "Enemy.h"

Enemy::Enemy()
{
    //ctor
}

Enemy::Enemy(float x, float y, List_Images *img):
        Character(x, y, img)
{}

void Enemy::setPosMatrix(){}

//Shows on screen the images in the images vector.
void Enemy::print(BITMAP* screen){
    masked_blit(current_img, screen, 0,0, x, y, w, h);
}

Enemy::~Enemy()
{
    //dtor
}
