#include "Human.h"

Human::Human()
{
    //ctor
}

Human::Human(string name, float x, float y, float x_speed, float y_speed, List_Images *img):
               Character(x, y, x_speed, y_speed, img){
    this->name = name;
    this->y_force = 0;
    setPosMatrix();
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
       y_force = 0;

/*
    else if(y_move < 0 && move_up == false)
        y_move = 0;
*/
    if(move_down == true)
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
    if(img->empty() || img == NULL){
        cout << "Erro carregando imagem (humano)." << endl;
        return;
    }
    masked_blit(current_img, screen, 0,0, x, y, w, h);
}

//Calculate collision of the character with another body (entity), return 1 if the collision happens
int Human::isCollide(Entity* Body)
{

    if((x >= Body->GetX()-w && x <= Body->GetX()+30) &&
       (y >= Body->GetY()-h && y <= Body->GetY()+30))
        return 1;

    if((x >= Body->GetX()-40 && x <= Body->GetX()+30) &&
        (y >= Body->GetY()-60 && y <= Body->GetY()+30))
            return 1;

    return 0;
}


void Human::isStructureCollide()
{

    int i,colission;
    float x_center,y_center,x_center_body,y_center_body;

    x_center = x+20;
    y_center = y+30;
    colission = 0;

    List_Structures* aux;
    aux = map->getList();


    colission = 0;
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
                 && abs(x_center - x_center_body) < 33)
                move_up = false;

            else if(x + w == (*aux)[i]->GetX() && abs(y_center - y_center_body) < 43)
                move_right = false;

            else if(x == (*aux)[i]->GetX() + 30 && abs(y_center - y_center_body) < 43)
                move_left = false;

            colission = 1;
        }
    }

    if(colission == 0)
    {
    }
}

Human::~Human()
{

}
