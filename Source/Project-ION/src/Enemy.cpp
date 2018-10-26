#include "Enemy.h"

Enemy::Enemy()
{
    //ctor
}

Enemy::Enemy(float x, float y, float x_speed, float y_speed, List_Images *img):
        Character(x, y, x_speed, y_speed, img)
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
