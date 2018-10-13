#include "Human.h"

Human::Human()
{
    //ctor
}

Human::Human(string name, float x, float y, float x_speed, float y_speed, std::vector<BITMAP*> *img):
               Character(x, y, x_speed, y_speed, img){
    this->name = name;
}

/*Move the character depending on x_move and y_move.
This parameters can be valued as 1, 0 or -1 (depending on the movement). */
void Human::move(int x_move, int y_move){
    x += x_speed*x_move;
    y += y_speed*y_move;
}

//Shows on screen the images in the images vector.
void Human::printCharacter(BITMAP* screen){
    if(img->empty() || img == NULL){
        cout << "Erro carregando imagem (humano)." << endl;
        return;
    }
    std::vector<BITMAP*>::iterator itr = img->begin();
    blit(*itr, screen, 0, 0, x, y, 40, 60);
}

Human::~Human()
{

}
