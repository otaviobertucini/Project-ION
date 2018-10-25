#include "Human.h"

Human::Human()
{
    //ctor
}

Human::Human(string name, float x, float y, float x_speed, float y_speed, List_Images *img):
               Character(x, y, x_speed, y_speed, img){
    this->name = name;
    setPosMatrix();
}

void Human::gravity(){
    if(move_down)
        y += y_speed;
}

/*Move the character depending on x_move and y_move.
This parameters can be valued as 1, 0 or -1 (depending on the movement). */
void Human::move(int x_move, int y_move)
{
    if(x_move > 0 && move_right == false)
        x_move = 0;
    else if(x_move < 0 && move_left == false)
        x_move = 0;

    if(y_move > 0 && move_down == false)
        y_move = 0;
    else if(y_move < 0 && move_up == false)
        y_move = 0;

    x += x_speed*x_move;
    y += y_speed*y_move;
    setPosMatrix();
}

// Returns the position in the matrix where the character is placed.
// Takes the left foot as reference so far.
void Human::setPosMatrix(){
    i_pos = (int)floor((y+60)/30);
    j_pos = (int)floor((x+40)/30)-1;
}

//Shows on screen the images in the images vector.
void Human::print(BITMAP* screen){
    if(img->empty() || img == NULL){
        cout << "Erro carregando imagem (humano)." << endl;
        return;
    }
    BITMAP* image = (*img)[0];
    blit(image, screen, 0, 0, x, y, 40, 60);
}

//Calculate collision of the character with another body (entity), return 1 if the collision happens
int Human::isCollide(Entity* Body)
{
    if((x >= Body->GetX()-40 && x <= Body->GetX()+30) &&
       (y >= Body->GetY()-60 && y <= Body->GetY()+30))
        return 1;
    return 0;
}

void Human::isStructureCollide()
{
    int i,colission;

    List_Structures* aux;
    aux = map->getList();

    colission = 0;
    for(i=0;i<aux->size();i++)
    {
        if(isCollide(static_cast<Entity*>((*aux)[i])) == 1)
        {
            if(y + 60 == (*aux)[i]->GetY())
                move_down = false;
            else if(y == (*aux)[i]->GetY() + 30)
                move_up = false;
            else if(x + 40 == (*aux)[i]->GetX())
                move_right = false;
            else if(x == (*aux)[i]->GetX() + 30)
                move_left = false;
            colission = 1;
        }
    }

    if(colission == 0)
    {
        move_left = true;
        move_right = true;
        move_up = true;
        move_down = true;
    }
}

/*int Human::collisionDirection(Entity* Body)
{
    return 0;
}
*/

Human::~Human()
{

}
