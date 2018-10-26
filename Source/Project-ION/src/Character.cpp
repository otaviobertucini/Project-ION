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
    /*if((x >= Body->GetX() && x <= Body->GetX()+30) &&
       (y >= Body->GetY() && y <= Body->GetY()+30))
       {
           cout << "1" << endl;
        return 1;
       }
    return 0;
    */
}


void Character::isStructureCollide()
{

    int i;
    float x_center,y_center,x_center_body,y_center_body;

    x_center = x+20;
    y_center = y+30;

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

        if(isCollide(static_cast<Entity*>((*aux)[i])) == 1)
        {

            if(y + h >= (*aux)[i]->GetY() && y + h <= (*aux)[i]->GetY() + 3
               && abs(x_center - x_center_body) < 33)
                move_down = false;

            else if(y <= (*aux)[i]->GetY() + 30 && y >= (*aux)[i]->GetY() + 27
                 && abs(x_center - x_center_body) < 33){
                move_up = false;
                move_down = true;
            }

            else if(x + w == (*aux)[i]->GetX() && abs(y_center - y_center_body) < 43)
                move_right = false;

            else if(x == (*aux)[i]->GetX() + 30 && abs(y_center - y_center_body) < 43)
                move_left = false;

        }
    }
}

void Character::setMap(Map* mp)
{
        map = mp;
}

Character::~Character()
{
    img->deleteAll();
}
