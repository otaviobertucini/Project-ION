#include "Human.h"

Human::Human()
{
    //ctor
}

Human::Human(string name, float x, float y, List_Images *img, int direction):
               Character(x, y, img){
    this->name = name;
    this->current_side = 1;
    this->charge = false;
    this->dashOn = false;
    setPosMatrix();
    h = 60;
    w = 40;
    x_speed = 0.6;
    y_speed = 0.6;
    this->direction = direction;
    invincible = false;
    powerup_on = false;
}

void Human::gravity()
{

    if(!dashOn)
    {
        float y_force_limit;

        if(move_up == false)
        {
            y_force = 0.2;
            move_up = true;
        }

        y_force_limit = 2;

        y_force += 0.02;

        if(y_force > y_force_limit)
            y_force = y_force_limit;

        if(move_down == false)
        {
           y_force = 0;
           charge = true;
        }
        y += y_force;
    }
}

void Human::jump()
{
    if(!move_down && !dashOn)
    {
        y_force = -2.5;
        move_down = true;
    }
}



void Human::JetPack()
{
    if(charge && !dashOn)
    {
        y_force = -2.7;
        move_down = true;
        charge = false;
    }
}

void Human::activeDash()
{
    if(charge && !dashOn)
    {
        dashOn = true;
        charge = false;
        y_force = 0;
        distance_dash = 0;
    }
}

void Human::loop(){
    dash();
    gravity();
    //isStructureCollide();
}

void Human::dash()
{

    float x_force = 2;

    if(dashOn)
    {
        if(distance_dash <= 210 &&
          ((move_left && current_side == 0) || (move_right && current_side == 1)))
        {
            if(current_side == 0)
                x-=x_force;
            else
                x+=x_force;

            distance_dash+=x_force;
        }
        else
        {
            dashOn = false;
        }
    }
}

/*Move the character depending on x_move and y_move.
This parameters can be valued as 1, 0 or -1 (depending on the movement). */
void Human::move(int x_move)
{
    direction = x_move;
    if(!dashOn)
    {
        if(x_move > 0)
        {
            current_side = 1;

            if(move_right == false)
                x_move = 0;
        }

        else if(x_move < 0)
        {
            current_side = 0;

            if(move_left == false)
                x_move = 0;
        }


        x += x_speed*x_move;
        setPosMatrix();
    }
}

// Returns the position in the matrix where the character is placed.
// Takes the left foot as reference so far.
void Human::setPosMatrix(){
    i_pos = (int)floor((y+h)/30);
    j_pos = (int)floor((x+w)/30)-1;
}

void Human::toInvincible(bool state){
    invincible = state;
}

bool Human::isInvincible(){
    return invincible;
}

void Human::turnPowerup(bool state){
    powerup_on = state;
}

bool Human::isPowered(){
    return powerup_on;
}

Human::~Human()
{

}
