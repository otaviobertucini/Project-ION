#include "SoloGame.h"

SoloGame::SoloGame():Game()
{
    images = new Images;
    menu1 = new Menu(buffer);
    levels = new List_Levels;

    chances = 3;
    i_level = 0;
    //Level 0
    level0();
}

void SoloGame::execute()
{
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
        if(start == 1)
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
                        if(pause == 0){
                            exit_loop = true;
                            dead = true;
                            current->resetLevel();
                        }
                        else if(pause == 2){
                            exit_loop = true;
                            dead = true;
                            saveLevel();
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

                    if(game_status == 3){
                        i_level--;
                        break;
                    }

                    draw_sprite(screen, buffer, 0, 0);
                    clear_bitmap(buffer);
                }
                current->resetLevel();
            }
        }
        if(start == 0){
            exit = true;
        }
        if(start == 2){
            readLevel();
            rest(400);
        }
    }
}

void SoloGame::level0(){
    jack = new Human("Jack", 0, 0, 0.6, 0.6, images->getImgsJack());

    Tutorial* tutorial = new Tutorial(buffer, images, jack);
    levels->include(static_cast<Level*>(tutorial));

    Level_1* level_1 = new Level_1(buffer, images, jack);
    levels->include(static_cast<Level*>(level_1));
}

void SoloGame::saveLevel(){
    List_Characters* characters = current->getListCharacters();
    ofstream myfile("register.txt");
    myfile << "LEV: " << i_level << "\n";
    myfile << "JAK: " << jack->getx() << "," << jack->gety() << "\n";
    for(int i = 0; i<(*characters).size(); i++){
        Character* c = (*characters)[i];
        myfile << c->getType() << ": " << c->getx() << "," << c->gety() << "\n";
    }
    //myfile << "###";
}

void SoloGame::readLevel(){
    ifstream myfile("register.txt");
    std::string line;
    if(myfile.is_open()){
        while (getline(myfile,line)){
            std::string copy(line.begin(), line.begin()+3);
            if(copy == "JAK"){
                ;
            }
        }
    }
}

SoloGame::~SoloGame()
{
}
