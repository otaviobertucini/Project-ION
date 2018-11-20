#include "SoloGame.h"

SoloGame::SoloGame(){}

SoloGame::SoloGame(Menu* menu, BITMAP* buffer):Game()
{
    this->buffer = buffer;
    listUsers.Import_List();
    menu1 = menu;
    chances = 3;
    i_level = 0;
    power_time = 0;

    //Level 0
    level0();
}

//Execute
void SoloGame::execute()
{
    int game_status;
    bool dead;
    int pause;
    float x,y,x_save,y_save;
    int runTime;
    int score;
    bool exit = false;
    bool exit_loop;
    int load_level = 0;
    int level_point = 0;
    int return_possible_archive;

    int start = menu1->sologame();

    if(start == 1)
        current_user.setName(menu1->readMenu());

    //Loop do jogo todo
    while(!exit)
    {
        x = 240;
        y = 140;
        i_level = 0;
        runTime = clock();

        if(start == 2){
            current_user.setName(menu1->readMenu());
            string aux_str = "Register/" + current_user.getName() + ".txt";
            ifstream file(aux_str.c_str());
            return_possible_archive = readLevel(file);
            if(return_possible_archive == 0)
                break;
            file.clear();
            file.seekg(0, ios::beg);
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

                            if(i_level == 7)
                                level_point = 2;

                            else if(i_level == 8)
                                level_point = 4;

                            else
                                level_point = i_level;
                            score = clock() - runTime;
                            current_user.setLevel(level_point);
                            current_user.setScore(score);
                            listUsers.Add_User(&current_user);
                            listUsers.Insertion_Sort_Level();
                            listUsers.Export_List();
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

                    if(game_status == 100){
                        score = clock() - runTime;
                        current_user.setLevel(8);
                        current_user.setScore(score);
                        listUsers.Add_User(&current_user);
                        listUsers.Insertion_Sort_Level();
                        listUsers.Export_List();
                        menu1->win();
                        dead = true;
                        exit_loop = true;
                        exit = true;
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

                    x = current->getXInitial();
                    y = current->getYInitial();
                }

                x_save = current->getXSaveInitial();
                y_save = current->getYSaveInitial();
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
    jack = new Human("JAK", 0, 0);

    Tutorial* tutorial = new Tutorial(buffer,  jack);
    levels->include(static_cast<Level*>(tutorial));

    Level_1* level_1 = new Level_1(buffer,  jack);
    levels->include(static_cast<Level*>(level_1));

    Level_2* level_2 = new Level_2(buffer,  jack);
    levels->include(static_cast<Level*>(level_2));

    Level_3* level_3 = new Level_3(buffer,  jack);
    levels->include(static_cast<Level*>(level_3));

    Level_4* level_4 = new Level_4(buffer,  jack);
    levels->include(static_cast<Level*>(level_4));

    Level_5* level_5 = new Level_5(buffer,  jack);
    levels->include(static_cast<Level*>(level_5));

    Level_6* level_6 = new Level_6(buffer,  jack);
    levels->include(static_cast<Level*>(level_6));

    Level_Boss* level_boss = new Level_Boss(buffer,  jack);
    levels->include(static_cast<Level*>(level_boss));

    Level_2_1* level_2_1 = new Level_2_1(buffer,  jack);
    levels->include(static_cast<Level*>(level_2_1));

    Level_4_1* level_4_1 = new Level_4_1(buffer,  jack);
    levels->include(static_cast<Level*>(level_4_1));
}

void SoloGame::saveLevel(){
    string aux = "Register/" + current_user.getName() + ".txt";
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
        while(getline(myfile, line))
        {
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
        }

        return 1;
    }
    return 0;
}

void SoloGame::resetLevels(){
    levels->eraseAll();
}

void SoloGame::deleteLevels(){
    levels->deleteAll();
}

SoloGame::~SoloGame()
{
    delete jack;
    jack = NULL;
    deleteLevels();
}
