#include "SoloGame.h"

SoloGame::SoloGame():Game()
{
    images = new Images;
    menu1 = new Menu(buffer);
    chances = 3;

    //Level 0
    level0();
}

//void SoloGame::menu(){
//    if(start)
//        execute();
//}

void SoloGame::execute()
{
    int died;
    int pause;
    bool exit = false;
    bool exit_loop;
    //Loop do jogo todo
    while(!exit)
    {
        int start = menu1->inicial();
        exit_loop = false;
        chances = 3;
        if(start)
        {
            //Loop de cada fase
            current->generateLevel();
            while(!key[KEY_ESC] && !exit_loop)
            {
                died = current->gameLoop();
                if(died == 0)
                {
                    chances--;
                    if(chances == 0)
                    {
                        break;
                    }
                    cout << "morreu" << endl;
                    current->resetPlayer();
                }

                if(key[KEY_P])
                {
                    pause = menu1->pause();
                    if(!pause){
                        exit_loop = true;
                    }
                }

                draw_sprite(screen, buffer, 0, 0);
                clear_bitmap(buffer);
            }
            current->resetLevel();
        }
        if(!start){
            exit = true;
        }
    }
}

void SoloGame::level0(){
    Tutorial* tutorial = new Tutorial(buffer, images);
    current = static_cast<Level*>(tutorial);
}

SoloGame::~SoloGame()
{
}
