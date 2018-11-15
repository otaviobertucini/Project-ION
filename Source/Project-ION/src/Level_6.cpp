#include "Level_6.h"

Level_6::Level_6()
{
    //ctor


}

Level_6::Level_6(BITMAP* buffer, Images* images, Human* jack):Level(buffer, images, jack){

    int** m = new int*[24];
    for(int i = 0; i<24; i++)
        m[i] = new int[36];

    int m1[24][36]
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 3, 3, 3, 0, 0, 3, 3, 3, 0, 0, 3, 3, 2, 2, 0, 3, 3, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0}
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

int Level_6::gameLoop(){


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

    if(jack->gety() >= 720){
        resetPlayer(jack->getx(),-20);
        return 3;
    }
    else if(jack->getx() >= 1075){
        resetPlayer(-15,jack->gety());
        return 2; //next level
    }

}

void Level_6::generateLevel()
{
    if(!was_genereted){

        resetLevel();

        if(rand()%2 == 0)
        {
            Topspin* top1 = new Topspin(720, 680, images->getImgsTopspin(),-1);
            characters->include(static_cast<Character*>(top1));
        }

        if(rand()%2 == 0)
        {
            Topspin* top2 = new Topspin(570, 400, images->getImgsTopspin(),-1);
            characters->include(static_cast<Character*>(top2));
        }

        if(rand()%2 == 0)
        {
            Topspin* top3 = new Topspin(420, 640, images->getImgsTopspin(),-1);
            characters->include(static_cast<Character*>(top3));
        }

        if(rand()%2 == 0)
        {
            Topspin* top4 = new Topspin(270, 610, images->getImgsTopspin(),-1);
            characters->include(static_cast<Character*>(top4));
        }

        if(rand()%2 == 0)
        {
            Topspin* top5 = new Topspin(60, 280, images->getImgsTopspin(),1);
            characters->include(static_cast<Character*>(top5));
        }


        if(rand()%2 == 0)
        {
            Bat* batman1 = new Bat(450,180,images->getImgsBat(),1,1,130,90);
            characters->include(static_cast<Character*>(batman1));
        }

        if(rand()%2 == 0)
        {
            Bat* batman2 = new Bat(300,210,images->getImgsBat(),1,1,40,430);
            characters->include(static_cast<Character*>(batman2));
        }

        if(rand()%2 == 0)
        {
            Bat* batman3 = new Bat(340,210,images->getImgsBat(),-1,1,40,430);
            characters->include(static_cast<Character*>(batman3));
        }

        if(rand()%2 == 0)
        {
            Bat* batman4 = new Bat(450,150,images->getImgsBat(),1,1,160,0);
            characters->include(static_cast<Character*>(batman4));
        }

        if(rand()%2 == 0)
        {
            Bat* batman5 = new Bat(150,30,images->getImgsBat(),1,1,50,600);
            characters->include(static_cast<Character*>(batman5));
        }

        was_genereted = 1;
    }

}

void Level_6::eraseAll(){
    characters->eraseAll();
    fireballs->eraseAll();
    was_genereted = 0;
}

void Level_6::saveLevel(std::ofstream& myfile) const{
    characters->saveLevel(myfile);
    fireballs->saveLevel(myfile);
}

void Level_6::loadLevel(ifstream& myfile){
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
                characters->include(static_cast<Character*>(new Topspin(x, y, images->getImgsTopspin(), dir)));
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
                characters->include(static_cast<Character*>(new Bat(x, y, images->getImgsBat(), dir, step, x_lim, y_lim, flew)));
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
                BITMAP* aux = load_bitmap("Material/Enemy/fireball.bmp", NULL);
                fireballs->include(static_cast<Fireball*>(new Fireball(x, y, aux)));
            }
        }
        was_genereted = 1;
    }
    else{
        cout << "NÃO ABRIU LULULULULUL" << endl;
    }
}

Level_6::~Level_6()
{
    //dtor
}

