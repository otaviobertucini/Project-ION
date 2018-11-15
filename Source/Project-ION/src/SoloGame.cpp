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
    //Loop do jogo todo
    while(!exit)
    {
        int load_level = 0;
        int start = menu1->sologame();

        x = 240;
        y = 140;

        chances = 100;
        i_level = 5;
        if(start == 2){
            ifstream file("register.txt");
            readLevel(file);
            current = (*levels)[i_level];
            current->loadLevel(file);

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
    ofstream myfile("register.txt");
    myfile << "LEV:" << i_level << "\n";
    myfile << "LIF:" << chances << "\n";
    myfile << "TIM:" << power_time << endl;
    jack->saveState(myfile);
    current->saveLevel(myfile);
}

void SoloGame::readLevel(ifstream& myfile){
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
            chances = ((int) atoi(lif.c_str()));
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
}

//void SoloGame::readLevel(List_Characters* characters, List_Powerups* powers, List_Fireballs* fires){
//    ifstream myfile("register.txt");
//    std::string line;
//    if(myfile.is_open()){
//        while (getline(myfile,line)){
//            std::string copy(line.begin(), line.begin()+3);
//            if(copy == "LEV"){
//                std::string lev(line, 4, line.size()-1);
//                i_level =((int) atoi(lev.c_str()));
//            }
//            if(copy == "LIF"){
//                std::string lif(line, 4, line.size()-1);
//                chances = ((int) atoi(lif.c_str()));
//            }
//            if(copy == "TIM"){
//                std::string lif(line, 4, line.size()-1);
//                power_time = ((float) atof(lif.c_str()));
//            }
//            if(copy == "JAK"){
//                int i;
//                std::vector<int> index;
//                for(i=4; i<line.size(); i++){
//                    if(line[i] == ',')
//                        index.push_back(i);
//                }
//                std::string x(line, 4, index[0]);
//                std::string y(line, index[0]+1, index[1]);
//                std::string dir_copy(line, index[1]+1, index[2]);
//                std::string power_copy(line, index[2]+1, line.size()-1);
//                jack->setx((float) atof(x.c_str()));
//                jack->sety((float) atof(y.c_str())-1);
//                jack->setDown(false);
//                jack->setUp(false);
//                jack->turnPowerup((int) atoi(power_copy.c_str()));
//            }
//            if(copy == "TOP"){
//                int i;
//                std::vector<int> index;
//                for(i=4; i<line.size(); i++){
//                    if(line[i] == ',')
//                        index.push_back(i);
//                }
//                std::string x_copy(line, 4, index[0]);
//                std::string y_copy(line, index[0]+1, index[1]);
//                std::string dir_copy(line, index[1]+1, line.size()-1);
//                float x = (float) atof(x_copy.c_str());
//                float y = (float) atof(y_copy.c_str());
//                int dir = (int) atoi(dir_copy.c_str());
//                characters->include(static_cast<Character*>(new Topspin(x, y, images->getImgsTopspin(), dir)));
//            }
//            if(copy == "BAT"){
//                int i;
//                std::vector<int> index;
//                for(i=4; i<line.size(); i++){
//                    if(line[i] == ',')
//                        index.push_back(i);
//                }
//                std::string x_copy(line, 4, index[0]);
//                std::string y_copy(line, index[0]+1, index[1]);
//                std::string dir_copy(line, index[1]+1, index[2]);
//                std::string step_copy(line, index[2]+1, index[3]);
//                std::string ylim_copy(line, index[3]+1, index[4]);
//                std::string xlim_copy(line, index[4]+1, index[5]);
//                std::string flew_copy(line, index[5]+1, line.size()-1);
//                float x = (float) atof(x_copy.c_str());
//                float y = (float) atof(y_copy.c_str());
//                int dir = (int) atoi(dir_copy.c_str());
//                int step = (int) atoi(step_copy.c_str());
//                int x_lim = (int) atoi(xlim_copy.c_str());
//                int y_lim = (int) atoi(ylim_copy.c_str());
//                float flew = (float) atof(flew_copy.c_str());
//                characters->include(static_cast<Character*>(new Bat(x, y, images->getImgsBat(), dir, step, x_lim, y_lim, flew)));
//            }
//            if(copy == "POW"){
//                int i;
//                std::vector<int> index;
//                for(i=4; i<line.size(); i++){
//                    if(line[i] == ',')
//                        index.push_back(i);
//                }
//                std::string x_copy(line, 4, index[0]);
//                std::string y_copy(line, index[0]+1, line.size()-1);
//                int x = (int) atoi(x_copy.c_str());
//                int y = (int) atoi(y_copy.c_str());
//                List_Images* aux = images->getImgsMap();
//                powers->include(static_cast<Powerup*>(new Birl(x, y, (*aux)[23])));
//            }
//            if(copy == "FIR"){
//                int i;
//                std::vector<int> index;
//                for(i=4; i<line.size(); i++){
//                    if(line[i] == ',')
//                        index.push_back(i);
//                }
//                std::string x_copy(line, 4, index[0]);
//                std::string y_copy(line, index[0]+1, line.size()-1);
//                int x = (int) atoi(x_copy.c_str());
//                int y = (int) atoi(y_copy.c_str());
//                cout << x << ", " << y << endl;
//                List_Images* aux = images->getImgsFireball();
//                fires->include(static_cast<Fireball*>(new Fireball(x, y, (*aux)[0])));
//            }
//        }
//    }
//}

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
