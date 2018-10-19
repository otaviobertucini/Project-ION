#include "Entity.h"

Entity::Entity()
{
    //ctor
}

Entity::Entity(float x, float y, std::vector<BITMAP*> *img){
    this->x = x;
    this->y = y;
    this->img = img;
}

void Entity::getPosMatrix(int* i, int* j){
    *i = i_pos;
    *j = j_pos;
}

Entity::~Entity()
{
    //dtor
}
