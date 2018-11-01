#include "SoloGame.h"

SoloGame::SoloGame():Game()
{
    images = new Images;
    menu1 = new Menu(buffer);
    levels = new List_Levels;

    chances = 3;

    //Level 0
    level0();
}

void SoloGame::execute()
{

    int i_level;
    int game_status;
    bool dead = false;
    int pause;
    bool exit = false;
    bool exit_loop;
    //Loop do jogo todo
    while(!exit)
    {

        int start = menu1->inicial();
        chances = 3;
        i_level = 0;
        if(start)
        {
            dead = false;
            //Loop de cada jogada
            while(!dead){
                exit_loop = false;
                current = (*levels)[i_level];
                current->generateLevel();
                //Loop de cada fase
                while(!exit_loop)
                {
                    game_status = current->gameLoop();

                    if(key[KEY_ESC])
                    {
                        pause = menu1->pause();
                        if(!pause){
                            exit_loop = true;
                            dead = true;
                            current->resetLevel();
                        }
                    }

                    if(game_status == 0)
                    {
                        chances--;
                        if(chances == 0)
                        {
                            dead = true;
                            break;
                        }
                        cout << "morreu" << endl;
                        current->resetPlayer();
                    }

                    if(game_status == 2){
                        i_level++;
                        break;
                    }

                    draw_sprite(screen, buffer, 0, 0);
                    clear_bitmap(buffer);
                }
                current->resetLevel();
            }
        }
        if(!start){
            exit = true;
        }
    }
}

void SoloGame::level0(){

    Human* jack = new Human("Jack", 0, 0, 0.6, 0.6, images->getImgsJack());

    Tutorial* tutorial = new Tutorial(buffer, images, jack);
    levels->include(static_cast<Level*>(tutorial));

    Level_1* level_1 = new Level_1(buffer, images, jack);
    levels->include(static_cast<Level*>(level_1));
}

SoloGame::~SoloGame()
{
}
