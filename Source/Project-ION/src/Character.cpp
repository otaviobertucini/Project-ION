#include "Character.h"

Character::Character()
{
    //ctor
}

Character::Character(float x, float y, List_Images *img):
            Entity(x, y)
{
    this->img = img;
    this->move_left = true;
    this->move_right = true;
    this->move_up = true;
    this->move_down = true;
    if(img != NULL)
        current_img = (*img)[0];
    direction = 1;
    y_force = 0;
}

//Apply Gravity
void Character::gravity()
{

    float y_force_limit;

    if(move_up == false)
    {
        y_force *= -0.5;
        move_up = true;
    }

    y_force_limit = 2;
    y_force += 0.02;

    if(y_force > y_force_limit)
        y_force = y_force_limit;

    if(move_down == false)
       y_force = 0;

    if(move_down == true)
       y += y_force;
}

std::string Character::getType(){
    return type;
}

void Character::setRight(bool new_mode){
    move_right = new_mode;
}

void Character::setLeft(bool new_mode){
    move_left = new_mode;
}

void Character::setUp(bool new_mode){
    move_up = new_mode;
}

void Character::setDown(bool new_mode){
    move_down = new_mode;
}

int Character::getDirection(){
    return direction;
}

Character::~Character()
{}
