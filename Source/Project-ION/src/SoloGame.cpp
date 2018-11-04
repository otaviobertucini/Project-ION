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
    bool dead;
    int pause;
    float x,y;
    bool exit = false;
    bool exit_loop;


    //Loop do jogo todo
    while(!exit)
    {
        int load_level = 0;
        int start = menu1->inicial();

        x = 240;
        y = 140;

        chances = 3;
        i_level = 0;
        List_Characters* characters = new List_Characters;
        if(start == 2){
            readLevel(characters);
            start = 1;
            load_level = 1;
        }
        if(start == 1)
        {
            dead = false;
            //Loop de cada jogada
            while(!dead){
                exit_loop = false;
                current = (*levels)[i_level];
                if(!load_level){
                    current->generateLevel();
                }
                else{
                    current->generateLevel(characters);
                }
                load_level = 0;
                current->resetPlayer(x,y);
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
                            exit_loop = true;
                        }
                        cout << "morreu" << endl;
                        current->resetPlayer();
                    }

                    if(game_status == 2){
                        i_level++;
                        exit_loop = true;
                    }

                    if(game_status == 3){
                        i_level--;
                        exit_loop = true;
                    }

                    x = current->getXInitial();
                    y = current->getYInitial();
                    draw_sprite(screen, buffer, 0, 0);
                    clear_bitmap(buffer);
                }

                current->resetLevel();
            }
        }
        if(start == 0){
            exit = true;
        }

    }
}

void SoloGame::level0(){
    jack = new Human("Jack", 0, 0, images->getImgsJack());

    Tutorial* tutorial = new Tutorial(buffer, images, jack);
    levels->include(static_cast<Level*>(tutorial));

    Level_1* level_1 = new Level_1(buffer, images, jack);
    levels->include(static_cast<Level*>(level_1));
}

void SoloGame::saveLevel(){
    List_Characters* characters = current->getListCharacters();
    ofstream myfile("register.txt");
    myfile << "LEV:" << i_level << "\n";
    myfile << "LIF:" << chances << "\n";
    myfile << "JAK:" << jack->getx() << "," << jack->gety() << "\n";
    for(int i = 0; i<(*characters).size(); i++){
        Character* c = (*characters)[i];
        myfile << c->getType() << ":" << c->getx() << "," << c->gety() << ","
                << c->getDirection() << "\n";
    }
}

void SoloGame::readLevel(List_Characters* characters){
    ifstream myfile("register.txt");
    std::string line;
    if(myfile.is_open()){
        while (getline(myfile,line)){
            std::string copy(line.begin(), line.begin()+3);
            if(copy == "LEV"){
                std::string lev(line, 4, line.size()-1);
                i_level =((int) atoi(lev.c_str()));
            }
            if(copy == "LIF"){
                std::string lif(line, 4, line.size()-1);
                chances = ((int) atoi(lif.c_str()));
            }
            if(copy == "JAK"){
                int i;
                for(i=4; i<line.size(); i++){
                    if(line[i] == ',')
                        break;
                }
                std::string x(line, 4, i);
                std::string y(line, i+1, line.size()-1);
                jack->setx((float) atof(x.c_str()));
                jack->sety((float) atof(y.c_str()));
                jack->setDown(false);
                jack->setUp(false);
            }
            if(copy == "TOP"){
                int i;
                std::vector<int> index;
                for(i=4; i<line.size(); i++){
                    if(line[i] == ',')
                        index.push_back(i);
                }
                std::string x_copy(line, 4, index[0]);
                std::string y_copy(line, index[0]+1, index[1]);
                std::string dir_copy(line, index[1]+1, line.size()-1);
                float x = (float) atof(x_copy.c_str());
                float y = (float) atof(y_copy.c_str());
                int dir = (int) atoi(dir_copy.c_str());
                characters->include(static_cast<Character*>(new Topspin(x, y, images->getImgsTopspin(), dir)));
            }
        }
    }
}

SoloGame::~SoloGame()
{
}
