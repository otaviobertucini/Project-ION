#include "Human.h"

Human::Human()
{
    //ctor
}

Human::Human(string name, float x, float y, float x_speed, float y_speed, List_Images *img):
               Character(x, y, x_speed, y_speed, img){
    this->name = name;
    this->y_force = 0;
    this->charge = false;
    setPosMatrix();
    h = 60;
    w = 40;
}

void Human::gravity()
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

void Human::jump()
{
    if(move_down == false)
    {
        y_force = -2.5;
        move_down = true;
    }
}

void Human::JetPack()
{
    if(charge == true)
    {
        y_force = -2.7;
        move_down = true;
        charge = false;
    }
}

/*Move the character depending on x_move and y_move.
This parameters can be valued as 1, 0 or -1 (depending on the movement). */
void Human::move(int x_move)
{
    if(x_move > 0 && move_right == false){
        x_move = 0;
    }
    else if(x_move < 0 && move_left == false){
        x_move = 0;
    }

    x += x_speed*x_move;
    setPosMatrix();
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
