#include "Character.h"

Character::Character()
{
    //ctor
}

Character::Character(float x, float y, float x_speed, float y_speed, List_Images *img):
            Entity(x, y)
{
    this->x_speed = x_speed;
    this->y_speed = y_speed;
    this->img = img;
    this->map = NULL;
    this->move_left = true;
    this->move_right = true;
    this->move_up = true;
    this->move_down = true;
    current_img = (*img)[0];
}

//Calculate collision of the character with another body (entity), return 1 if the collision happens
int Character::isCollide(Entity* Body)
{
    int x_sum = (w/2)+(Body->GetW()/2);
    int y_sum = (h/2)+(Body->GetH()/2);

    if((abs(x - Body->GetX()) <= x_sum) && (abs(y - Body->GetY()) <= y_sum ))
        return 1;
    return 0;
}

void Character::isStructureCollide()
{

    int i;
    float x_center,y_center,x_center_body,y_center_body;
    x_center = x+(w/2);
    y_center = y+(h/2);

    List_Structures* aux;
    aux = map->getList();

    move_left = true;
    move_right = true;
    move_up = true;
    move_down = true;

    for(i=0;i<aux->size();i++)
    {

        x_center_body = (*aux)[i]->GetX() + 15;
        y_center_body = (*aux)[i]->GetY() + 15;

        //if( isCollide(static_cast<Entity*>((*aux)[i])) == 1 )
        //{
            if(y + h >= (*aux)[i]->GetY() && y + h <= (*aux)[i]->GetY() + 3
               && abs(x_center - x_center_body) < 33)
                move_down = false;

            if(y <= (*aux)[i]->GetY() + 30 && y >= (*aux)[i]->GetY() + 27
                 && abs(x_center - x_center_body) < 33){
                move_up = false;
            }
            if(x + w == (*aux)[i]->GetX() && abs(y_center - y_center_body) < w+3)
                move_right = false;

            if(x == (*aux)[i]->GetX() + 30 && abs(y_center - y_center_body) < w+3)
                move_left = false;
        //}
    }
}

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

/*
    else if(y_move < 0 && move_up == false)
        y_move = 0;
*/
    if(move_down == true)
       y += y_force;
}

void Character::setMap(Map* mp)
{
        map = mp;
}

Character::~Character()
{
    img->deleteAll();
}
