#include "Character.h"

Character::Character()
{
    //ctor
}

Character::Character(float x, float y):
            Mover(x, y)
{
    this->move_left = true;
    this->move_right = true;
    this->move_up = true;
    this->move_down = true;
    direction = 1;
    y_force = 0;
}

//Apply Gravity
void Character::gravity()
{
    if(move_up == false)
    {
        y_force *= -0.5;
        move_up = true;
    }

    y_force += 0.02;

    if(y_force > 2)
        y_force = 2;

    if(move_down == false)
       y_force = 0;

    if(move_down == true)
       y += y_force;
}

void Character::operator++(int n){
    loop();
}

Character::~Character()
{}
