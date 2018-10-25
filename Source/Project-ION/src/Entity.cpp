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

float Entity::GetX()
{
    return x;
}

float Entity::GetY()
{
    return y;
}

void Entity::getPosMatrix(int* i, int* j){
    *i = i_pos;
    *j = j_pos;
}

Entity::~Entity()
{
    destroy_bitmap(current_img);
}
