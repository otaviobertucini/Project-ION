#include "Level_2.h"

Level_2::Level_2()
{

}

Level_2::Level_2(BITMAP* buffer, Human* jack):Level(buffer, jack)
{
    int** m = new int*[24];
    for(int i = 0; i<24; i++)
        m[i] = new int[36];

    int m1[24][36]
    {
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1},
        {0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 3, 2, 2, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    for(int i = 0; i<24; i++)
    {
        for(int j = 0; j<36; j++)
        {
            m[i][j] = m1[i][j];
        }
    }

    fireballs = new List_Fireballs;
    powers = new List_Powerups;
    generateMap(m);
}

int Level_2::gameLoop()
{

    game_status = genericGameLoop();

    powers->print(buffer);
    if(powers->isCollide(jack)){
        start = clock();
    }

    if(jack->isPowered()){
        int stop = clock();
        power_time = (stop-start)/double(CLOCKS_PER_SEC)*1000;

        if(power_time >= 5000){
            jack->turnPowerup(false);
        }
    }

    if(iterations % 4 == 0){
        fireballs->print(buffer);
    }

    if(iterations % 7 == 0){
        lavas->createFireballs(fireballs);
    }

    if(iterations == 3){
        structures->isCollide(fireballs);
        fireballs->loop();
    }

    if(iterations == 5){
        if(fireballs->isCollide(jack)){
            return 0;
        }
    }

    if(game_status != 1)
        return game_status;

    if(jack->getx() >= 1075 && jack->gety() >= 0){
        x_save_initial = 90;
        y_save_initial = 480;
        resetPlayer(-15,jack->gety());
        return 2; //next level
    }
    else if(jack->getx() <= -20){
        x_save_initial = 990;
        y_save_initial = 180;
        resetPlayer(1050,jack->gety());
        return 3; //prev level
    }
    else if(jack->gety() <= -30){
        x_save_initial = 180;
        y_save_initial = 570;
        resetPlayer(jack->getx(),710);
        return 4;
    }

}

void Level_2::generateLevel(){

    if(!was_genereted)
    {
        resetLevel();
        powers->include(static_cast<Powerup*>(new Birl(270, 570)));
        if(rand()%2 == 0)
        {
            Topspin* top = new Topspin(330,589, -1);
            characters->include(static_cast<Character*>(top));
        }

        if(rand()%2 == 0)
        {
            Topspin* top2 = new Topspin(480,619,1);
            characters->include(static_cast<Character*>(top2));
        }

        if(rand()%2 == 0)
        {
            Topspin* top3 = new Topspin(870,420,-1);
            characters->include(static_cast<Character*>(top3));
        }

        if(rand()%2 == 0)
        {
            Topspin* top4 = new Topspin(120,560,-1);
            characters->include(static_cast<Character*>(top4));
        }

        if(rand()%2 == 0)
        {
            Topspin* top5 = new Topspin(240,180,-1);
            characters->include(static_cast<Character*>(top5));
        }

        if(rand()%2 == 0)
        {
            Bat* batman1 = new Bat(90,90,1,1,50,320);
            characters->include(static_cast<Character*>(batman1));
        }

        if(rand()%2 == 0)
        {
            Bat* batman2 = new Bat(300,330,1,1,280,120);
            characters->include(static_cast<Character*>(batman2));
        }

        if(rand()%2 == 0)
        {
            Bat* batman3 = new Bat(580,330,-1,1,280,120);
            characters->include(static_cast<Character*>(batman3));
        }

        if(rand()%2 == 0)
        {
            Bat* batman4 = new Bat(690,530,1,1,60,90);
            characters->include(static_cast<Character*>(batman4));
        }

        if(rand()%2 == 0)
        {
            Bat* batman5 = new Bat(800,60,1,1,60,210);
            characters->include(static_cast<Character*>(batman5));
        }
        was_genereted = 1;
    }
}

void Level_2::eraseAll(){
    characters->eraseAll();
    fireballs->eraseAll();
    powers->eraseAll();
    was_genereted = 0;
}

void Level_2::printText(){
    if(jack->isPowered()){
        int sub = ((5000 - power_time)/1000)+1;
        std::stringstream ss;
        ss << "Birl: " << sub;
        std::string timer_txt = ss.str();
        textout_ex(buffer, font_main, timer_txt.c_str(), 900, 0, makecol(255, 0, 0), -1);
    }
    std::stringstream ss;
    ss << "Vidas: " << jack->getLifes();
    life_txt = ss.str();
    textout_ex(buffer, font_main, life_txt.c_str(), 0, 0, makecol(255, 0, 0), -1);
}

void Level_2::saveLevel(std::ofstream& myfile) const{
    characters->saveLevel(myfile);
    fireballs->saveLevel(myfile);
    powers->saveLevel(myfile);
}

void Level_2::loadLevel(ifstream& myfile){
    std::string line;
    if(myfile.is_open()){
        while (getline(myfile,line)){
            std::string copy(line.begin(), line.begin()+3);
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
                characters->include(static_cast<Character*>(new Topspin(x, y, dir)));
            }
            if(copy == "BAT"){
                int i;
                std::vector<int> index;
                for(i=4; i<line.size(); i++){
                    if(line[i] == ',')
                        index.push_back(i);
                }
                std::string x_copy(line, 4, index[0]);
                std::string y_copy(line, index[0]+1, index[1]);
                std::string dir_copy(line, index[1]+1, index[2]);
                std::string step_copy(line, index[2]+1, index[3]);
                std::string ylim_copy(line, index[3]+1, index[4]);
                std::string xlim_copy(line, index[4]+1, index[5]);
                std::string flew_copy(line, index[5]+1, line.size()-1);
                float x = (float) atof(x_copy.c_str());
                float y = (float) atof(y_copy.c_str());
                int dir = (int) atoi(dir_copy.c_str());
                int step = (int) atoi(step_copy.c_str());
                int x_lim = (int) atoi(xlim_copy.c_str());
                int y_lim = (int) atoi(ylim_copy.c_str());
                float flew = (float) atof(flew_copy.c_str());
                characters->include(static_cast<Character*>(new Bat(x, y, dir, step, x_lim, y_lim, flew)));
            }
            if(copy == "FIR"){
                int i;
                std::vector<int> index;
                for(i=4; i<line.size(); i++){
                    if(line[i] == ',')
                        index.push_back(i);
                }
                std::string x_copy(line, 4, index[0]);
                std::string y_copy(line, index[0]+1, line.size()-1);
                int x = (int) atoi(x_copy.c_str());
                int y = (int) atoi(y_copy.c_str());
                fireballs->include(static_cast<Fireball*>(new Fireball(x, y)));
            }
            if(copy == "POW"){
                int i;
                std::vector<int> index;
                for(i=4; i<line.size(); i++){
                    if(line[i] == ',')
                        index.push_back(i);
                }
                std::string x_copy(line, 4, index[0]);
                std::string y_copy(line, index[0]+1, line.size()-1);
                int x = (int) atoi(x_copy.c_str());
                int y = (int) atoi(y_copy.c_str());

                powers->include(static_cast<Powerup*>(new Birl(x, y)));
            }
        }
        was_genereted = 1;
    }
    else{
        cout << "Erro ao carregar arquivo!" << endl;
    }
}

Level_2::~Level_2()
{}
