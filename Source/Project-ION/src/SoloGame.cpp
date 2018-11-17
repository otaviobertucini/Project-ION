#include "SoloGame.h"

SoloGame::SoloGame(){}

SoloGame::SoloGame(Menu* menu, BITMAP* buffer):Game()
{
    this->buffer = buffer;
    menu1 = menu;
    chances = 3;
    i_level = 0;
    power_time = 0;

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
    int load_level = 0;
    int return_possible_archive;

    int start = menu1->sologame();

    if(start == 1)
        usuario.setName(menu1->readMenu());

    //Loop do jogo todo
    while(!exit)
    {

        x = 240;
        y = 140;

        chances = 100;
        i_level = 0;

        if(start == 2){
            usuario.setName(menu1->readMenu());
            string aux_str = "Register/" + usuario.getName() + ".txt";
            ifstream file(aux_str.c_str());
            return_possible_archive = readLevel(file);

            if(return_possible_archive == 0)
                break;

            current = (*levels)[i_level];
            current->loadLevel(file);
            current->resetPlayer(jack->getx(),jack->gety());

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
                    current->resetPlayer(x,y);
                }
                current->generateLevel();

                load_level = 0;

                //Loop de cada fase
                while(!exit_loop)
                {
                    int start = clock();
                    rest(0);
                    game_status = current->gameLoop();

                    if(key[KEY_ESC])
                    {
                        pause = menu1->pause();

                        if(pause == 0){
                            exit_loop = true;
                            dead = true;
                            exit = true;
                            saveLevel();
                        }
                    }

                    if(game_status == 0)
                    {
                        jack->lessLife();
                        if(jack->getLifes() == 0)
                        {
                            dead = true;
                            exit_loop = true;
                            jack->resetLifes();
                        }
                        current->resetPlayer();
                    }

                    if(game_status == 2){
                        i_level++;
                        exit_loop = true;
                    }
                    else if(game_status == 3){
                        i_level--;
                        exit_loop = true;
                    }
                    else if(game_status == 4){
                        i_level+=6;
                        exit_loop = true;
                    }
                    else if(game_status == 5){
                        i_level-=6;
                        exit_loop = true;
                    }
                    else if(game_status == 6){
                        i_level+=5;
                        exit_loop = true;
                    }
                    else if(game_status == 7){
                        i_level-=5;
                        exit_loop = true;
                    }
                    if(game_status == 20){
                        power_time = 0;
                    }
                    if(jack->isPowered()){
                        int stop = clock();
                        power_time += (stop-start)/double(CLOCKS_PER_SEC)*1000;

                        //cout << power_time << endl;
                        if(power_time >= 5000){
                            jack->turnPowerup(false);
                            //cout << "terminou power" << endl;
                        }
                    }

                    x = current->getXInitial();
                    y = current->getYInitial();
                }
                current->resetLevel();
            }
            resetLevels();
        }
        if(start == 0){
            exit = true;
        }

    }
}

void SoloGame::level0(){
    jack = new Human("JAK", 0, 0, images->getImgsJack());

    Tutorial* tutorial = new Tutorial(buffer, images, jack);
    levels->include(static_cast<Level*>(tutorial));

    Level_1* level_1 = new Level_1(buffer, images, jack);
    levels->include(static_cast<Level*>(level_1));

    Level_2* level_2 = new Level_2(buffer, images, jack);
    levels->include(static_cast<Level*>(level_2));

    Level_3* level_3 = new Level_3(buffer, images, jack);
    levels->include(static_cast<Level*>(level_3));

    Level_4* level_4 = new Level_4(buffer, images, jack);
    levels->include(static_cast<Level*>(level_4));

    Level_5* level_5 = new Level_5(buffer, images, jack);
    levels->include(static_cast<Level*>(level_5));

    Level_6* level_6 = new Level_6(buffer, images, jack);
    levels->include(static_cast<Level*>(level_6));

    Level_Boss* level_boss = new Level_Boss(buffer, images, jack);
    levels->include(static_cast<Level*>(level_boss));

    Level_2_1* level_2_1 = new Level_2_1(buffer, images, jack);
    levels->include(static_cast<Level*>(level_2_1));

    Level_4_1* level_4_1 = new Level_4_1(buffer, images, jack);
    levels->include(static_cast<Level*>(level_4_1));
}

void SoloGame::saveLevel(){

    string aux = "Register/" + usuario.getName() + ".txt";
    ofstream myfile(aux.c_str());
    myfile << "LEV:" << i_level << "\n";
    myfile << "LIF:" << jack->getLifes() << "\n";
    myfile << "TIM:" << power_time << endl;
    jack->saveState(myfile);
    current->saveLevel(myfile);
}

int SoloGame::readLevel(ifstream& myfile){
    std::string line;
    if(myfile.is_open()){
            getline(myfile, line);
            std::string copy(line.begin(), line.begin()+3);
            if(copy == "LEV"){
                std::string lev(line, 4, line.size()-1);
                i_level = ((int) atoi(lev.c_str()));
            }
            if(copy == "LIF"){
                std::string lif(line, 4, line.size()-1);
                jack->setLifes((int) atoi(lif.c_str()));
            }
            if(copy == "TIM"){
                std::string lif(line, 4, line.size()-1);
                power_time = ((float) atof(lif.c_str()));
            }
            if(copy == "JAK"){
                int i;
                std::vector<int> index;
                for(i=4; i<line.size(); i++){
                    if(line[i] == ',')
                        index.push_back(i);
                }
                std::string x(line, 4, index[0]);
                std::string y(line, index[0]+1, index[1]);
                std::string dir_copy(line, index[1]+1, index[2]);
                std::string power_copy(line, index[2]+1, line.size()-1);
                jack->setx((float) atof(x.c_str()));
                jack->sety((float) atof(y.c_str())-1);
                jack->setDown(false);
                jack->setUp(false);
                jack->turnPowerup((int) atoi(power_copy.c_str()));
            }

        return 1;
    }
    else
        return 0;
}

void SoloGame::resetLevels(){
    for(int i = 0; i<levels->size(); i++){
        (*levels)[i]->eraseAll();
    }
}

void SoloGame::deleteLevels(){
    for(unsigned int i = 0; i<levels->size(); i++){
        delete (*levels)[i];
    }
}

SoloGame::~SoloGame()
{
    delete jack;
    jack = NULL;
    deleteLevels();
}
