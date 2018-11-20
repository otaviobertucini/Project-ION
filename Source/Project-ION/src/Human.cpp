#include "Human.h"

Human::Human(): x_force(2)
{
    //ctor
}

Human::Human(string name, float x, float y, int direction, bool powerup_on):
               Character(x, y), x_force(2){
    this->name = name;
    this->current_side = 1;
    this->charge = false;
    this->dashOn = false;
    h = 60;
    w = 40;
    x_speed = 0.6;
    y_speed = 0.6;
    this->direction = direction;
    this->powerup_on = powerup_on;
    lifes = 10;
    distance_walk_animation = 0;
    walk = true;
    List_Images* img = Images_Library::imgsJack;
    current_img = (*img)[0];
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

void Human::animation()
{
    List_Images* imgs = Images_Library::imgsJack;
    if(current_side == 1)
    {
        if(!move_down && distance_walk_animation > 55)
        {
            if(walk)
            {
                current_img = (*imgs)[1];
                walk = false;
            }
            else
            {
                current_img = (*imgs)[0];
                walk = true;
            }
            distance_walk_animation = 0;
        }
        else if(move_down)
            current_img = (*imgs)[1];
    }
    else
    {
        if(!move_down && distance_walk_animation > 55)
        {
            if(walk)
            {
                current_img = (*imgs)[3];
                walk = false;
            }
            else
            {
                current_img = (*imgs)[2];
                walk = true;
            }
            distance_walk_animation = 0;
        }
        else if(move_down)
            current_img = (*imgs)[3];
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
}

void Human::dash()
{

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
        distance_walk_animation+= x_speed;
    }
}

void Human::turnPowerup(const bool state){
    powerup_on = state;
}

const bool Human::isPowered() const{
    return powerup_on;
}

void Human::saveState(std::ofstream& myfile) const{
    myfile << name << ":" << x << "," << y << "," << direction << "," << powerup_on << "\n";
}

int Human::getLifes(){
    return lifes;
}

void Human::lessLife(){
    lifes--;
}

void Human::resetLifes(){
    lifes = 10;
}

void Human::setLifes(const int lifes){
    this->lifes = lifes;
}

Human::~Human()
{

}
