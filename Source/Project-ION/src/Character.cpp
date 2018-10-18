#include "Character.h"

Character::Character()
{
    //ctor
}

Character::Character(float x, float y, float x_speed, float y_speed, std::vector<BITMAP*> *img){
    this->x = x;
    this->y = y;
    this->x_speed = x_speed;
    this->y_speed = y_speed;
    this->img = img;
    getPosMatrix(&i_pos, &j_pos);
}

// Returns the position in the matrix where the character is placed.
// Takes the left foot as reference so far.
void Character::getPosMatrix(int *i, int *j){
    *j = (int)floor((y+60)/30);
    *i = (int)floor((x+40)/30)-1;
}

Character::~Character()
{
    std::vector<BITMAP*>::iterator itr = img->begin();
    for(itr; itr != img->end(); itr++)
        delete *itr;
    img->clear();
}
