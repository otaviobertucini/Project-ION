#include "Human.h"

Human::Human()
{
    //ctor
}

Human::Human(string name, float x, float y, float x_speed, float y_speed, List_Images *img):
               Character(x, y, x_speed, y_speed, img){
    this->name = name;
    this->y_force = 0;
    this->current_side = 1;
    this->charge = false;
    this->dashOn = false;
    setPosMatrix();
    h = 60;
    w = 40;
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

    /*
        else if(y_move < 0 && move_up == false)
            y_move = 0;
    */
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
    gravity();
    dash();
    isStructureCollide();
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

//Shows on screen the images in the images vector.
void Human::print(BITMAP* screen){
    masked_blit(current_img, screen, 0,0, x, y, w, h);
}

Human::~Human()
{

}
