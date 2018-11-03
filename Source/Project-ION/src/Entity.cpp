#include "Entity.h"

Entity::Entity()
{
    //ctor
}

Entity::Entity(float x, float y, BITMAP* curren_img){
    this->x = x;
    this->y = y;
    this->current_img = curren_img;
}

BITMAP* Entity::getCurrentImg(){
    return current_img;
}

float Entity::getx()
{
    return x;
}

float Entity::gety()
{
    return y;
}

int Entity::getw()
{
    return w;
}

int Entity::geth()
{
    return h;
}

void Entity::sety(float new_y){
    y = new_y;
}

void Entity::setx(float new_x){
    x = new_x;
}

void Entity::getPosMatrix(int* i, int* j){
    *i = i_pos;
    *j = j_pos;
}

//Shows on screen the images in the images vector.
void Entity::print(BITMAP* screen){
    masked_blit(current_img, screen, 0,0, x, y, w, h);
}

Entity::~Entity()
{
}
