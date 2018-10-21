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

/*Move the character depending on x_move and y_move.
This parameters can be valued as 1, 0 or -1 (depending on the movement). */
void Human::move(int x_move, int y_move){
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

Human::~Human()
{

}
