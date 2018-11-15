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

const float Entity::getx() const
{
    return x;
}

const float Entity::gety() const
{
    return y;
}

const int Entity::getw() const
{
    return w;
}

const int Entity::geth() const
{
    return h;
}

void Entity::sety(const float new_y){
    y = new_y;
}

void Entity::setx(const float new_x){
    x = new_x;
}

//Shows on screen the images in the images vector.
void Entity::print(BITMAP* screen){
    masked_blit(current_img, screen, 0,0, x, y, w, h);
}

Entity::~Entity()
{
}
