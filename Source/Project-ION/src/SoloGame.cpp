#include "SoloGame.h"

SoloGame::SoloGame():Game()
{
    images = new Images;
    menu1 = new Menu(buffer);

    //Level 0
    level0();
}

void SoloGame::menu(){
    int start = menu1->inicial();
    if(start)
        execute();
}

void SoloGame::execute()
{
    int morreu;
    int pause;
    while(!key[KEY_ESC])
    {
        morreu = current->gameLoop();
        if(key[KEY_P]){
            pause = menu1->pause();
            if(!pause)
                break;
        }
        if(morreu == 0){
            cout << "morreu" << endl;
            break;
        }
        draw_sprite(screen, buffer, 0, 0);
        clear_bitmap(buffer);
    }
}

void SoloGame::level0(){
    Tutorial* tutorial = new Tutorial(buffer, images);
    current = static_cast<Level*>(tutorial);
}

SoloGame::~SoloGame()
{
}
