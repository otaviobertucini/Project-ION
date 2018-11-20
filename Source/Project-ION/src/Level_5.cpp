#include "Level_5.h"

Level_5::Level_5()
{
    //ctor


}

Level_5::Level_5(BITMAP* buffer, Human* jack):Level(buffer, jack){

    int** m = new int*[24];
    for(int i = 0; i<24; i++)
        m[i] = new int[36];

    int m1[24][36]
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 2, 3, 3, 2, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 0, 0, 0, 0, 2, 3, 3, 3, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 0, 0, 0, 0, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    for(int i = 0; i<24; i++)
    {
        for(int j = 0; j<36; j++)
        {
            m[i][j] = m1[i][j];
        }
    }

    fireballs = new List_Fireballs;
    generateMap(m);
}

int Level_5::gameLoop(){


    game_status = genericGameLoop();

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

    if(jack->getx() <= -20){
        x_save_initial = 960;
        y_save_initial = 90;
        resetPlayer(1050,jack->gety());
        return 3; //prev level
    }
    else if(jack->gety() <= -30){
        x_save_initial = 750;
        y_save_initial = 630;
        resetPlayer(jack->getx(),710);
        return 2;
    }

}

void Level_5::generateLevel(){

    if(!was_genereted){
        resetLevel();
        if(rand()%2 == 0)
        {
            Topspin* top1 = new Topspin(150, 190);
            characters->include(static_cast<Character*>(top1));
        }

        if(rand()%2 == 0)
        {
            Topspin* top2 = new Topspin(210, 330);
            characters->include(static_cast<Character*>(top2));
        }

        if(rand()%2 == 0)
        {
            Topspin* top3 = new Topspin(950, 680,-1);
            characters->include(static_cast<Character*>(top3));
        }

        if(rand()%2 == 0)
        {
            Topspin* top4 = new Topspin(510, 400,-1);
            characters->include(static_cast<Character*>(top4));
        }

        if(rand()%2 == 0)
        {
            Topspin* top5 = new Topspin(60, 510,-1);
            characters->include(static_cast<Character*>(top5));
        }


        if(rand()%2 == 0)
        {
            Bat* batman1 = new Bat(720,510,1,1,150,60);
            characters->include(static_cast<Character*>(batman1));
        }

        if(rand()%2 == 0)
        {
            Bat* batman2 = new Bat(480,90,1,1,330,130);
            characters->include(static_cast<Character*>(batman2));
        }

        if(rand()%2 == 0)
        {
            Bat* batman3 = new Bat(810,90,-1,1,330,130);
            characters->include(static_cast<Character*>(batman3));
        }

        if(rand()%2 == 0)
        {
            Bat* batman4 = new Bat(420,450,1,1,180,90);
            characters->include(static_cast<Character*>(batman4));
        }

        if(rand()%2 == 0)
        {
            Bat* batman5 = new Bat(480,90,1,1,330,0);
            characters->include(static_cast<Character*>(batman5));
        }

        was_genereted = 1;
    }
}


void Level_5::eraseAll(){
    characters->eraseAll();
    fireballs->eraseAll();
    was_genereted = 0;
}

void Level_5::saveLevel(std::ofstream& myfile) const{
    characters->saveLevel(myfile);
    fireballs->saveLevel(myfile);
}

void Level_5::loadLevel(ifstream& myfile){
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
        }
        was_genereted = 1;
    }
    else{
        cout << "Erro ao carregar arquivo!" << endl;
    }
}

Level_5::~Level_5()
{
    //dtor
}
