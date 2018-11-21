#include "Level.h"

Level::Level()
{
    //ctor
}

Level::Level(BITMAP* buffer, Human* jack){
    this->buffer = buffer;
    characters = new List_Characters;
    obstacles = new List_Obstacles;
    structures = new List_Structures;
    lavas = new List_Lavas;
    this->jack = jack;
    font_main = load_font("Fonts/ImpactFont.pcx", NULL, NULL);
    game_status = 1;
    was_genereted = 0;
    iterations = 0;
}

void Level::generateMap(int** matrix){
    bool upStone;
    bool downStone;
    bool leftStone;
    bool rightStone;
    srand(time(NULL));

    for(int i = 0; i<24; i++){
        for(int j = 0; j<36; j++){

            if(matrix[i][j] == 0)
            {
                upStone = false;
                downStone = false;
                leftStone = false;
                rightStone = false;

                if(i != 0 && matrix[i-1][j] != 0)
                    upStone = true;
                if(j != 35 && matrix[i][j+1] != 0)
                    rightStone = true;
                if(i != 23 && matrix[i+1][j] != 0)
                    downStone = true;
                if(j != 0 && matrix[i][j-1] != 0)
                    leftStone = true;

                if(upStone)
                {
                    if(downStone)
                    {
                        if(rightStone)
                            structures->include(static_cast<Structure*>(new Stone(30*j, 30*i, 13)));
                        else if(leftStone)
                            structures->include(static_cast<Structure*>(new Stone(30*j, 30*i, 15)));
                        else
                            structures->include(static_cast<Structure*>(new Stone(30*j, 30*i, 11)));
                    }
                    else if(rightStone)
                    {
                        if(leftStone)
                            structures->include(static_cast<Structure*>(new Stone(30*j, 30*i, 16)));
                        else
                            structures->include(static_cast<Structure*>(new Stone(30*j, 30*i, 7)));
                    }
                    else if(leftStone)
                        structures->include(static_cast<Structure*>(new Stone(30*j, 30*i, 10)));
                    else
                        structures->include(static_cast<Structure*>(new Stone(30*j, 30*i, 3)));
                }
                else if(rightStone)
                {
                    if(leftStone)
                    {
                        if(downStone)
                            structures->include(static_cast<Structure*>(new Stone(30*j, 30*i, 14)));
                        else
                            structures->include(static_cast<Structure*>(new Stone(30*j, 30*i, 12)));
                    }
                    else if(downStone)
                        structures->include(static_cast<Structure*>(new Stone(30*j, 30*i, 8)));
                    else
                        structures->include(static_cast<Structure*>(new Stone(30*j, 30*i, 4)));
                }
                else if(downStone)
                {
                    if(leftStone)
                        structures->include(static_cast<Structure*>(new Stone(30*j, 30*i, 9)));
                    else
                        structures->include(static_cast<Structure*>(new Stone(30*j, 30*i, 5)));
                }
                else if(leftStone)
                        structures->include(static_cast<Structure*>(new Stone(30*j, 30*i, 6)));
                else
                {
                    int aux;
                    aux = rand()%3;
                    structures->include(static_cast<Structure*>(new Stone(30*j, 30*i, aux)));
                }
            }
            else if(matrix[i][j] == 2){
                Lava* aux;
                if(matrix[i-1][j] != 2 && matrix[i-1][j] != 3)
                    aux = new Lava(30*j, 30*i, 1);
                else
                    aux = new Lava(30*j, 30*i, 0);
                obstacles->include(static_cast<Obstacle*>(aux));
            }
            else if(matrix[i][j] == 3){
                Lava* aux = new Lava(30*j, 30*i, 1);
                obstacles->include(static_cast<Obstacle*>(aux));
                lavas->include(aux);
            }
            else if(matrix[i][j] == 4){

                int aux;
                aux = rand()%2;

                if(aux == 0)
                {
                    int side;
                    if(matrix[i-1][j] == 0){
                        side = 21;
                    }
                    else if(matrix[i+1][j] == 0){
                        side = 19;
                    }
                    else if(matrix[i][j+1] == 0){
                        side = 22;
                    }
                    else if(matrix[i][j-1] == 0){
                        side = 20;
                    }
                    obstacles->include(static_cast<Obstacle*>(new Spine(30*j, 30*i, side)));
                }
            }
        }
    }
}

/*This function print the background of the level.*/
void Level::printMap(){
    structures->print(buffer);
    obstacles->print(buffer);
}

const float Level::getXInitial()
{
    return x_initial;
}

const float Level::getYInitial()
{
    return y_initial;
}

const float Level::getXSaveInitial()
{
    return x_save_initial;
}

const float Level::getYSaveInitial()
{
    return y_save_initial;
}

void Level::setInitial(float x, float y)
{
    x_initial = x;
    y_initial = y;
}

void Level::resetPlayer(){
    jack->setx(x_initial);
    jack->sety(y_initial);
    jack->setUp(false);
    jack->setDown(false);
    jack->turnPowerup(false);
}

void Level::resetPlayer(float x, float y){
    x_initial = x;
    y_initial = y;
    resetPlayer();
}

void Level::resetLevel(){
    resetPlayer();
}

void Level::eraseAll(){
    characters->eraseAll();
    was_genereted = 0;
}

void Level::printText(){
    std::stringstream ss;
    ss << "Vidas: " << jack->getLifes();
    life_txt = ss.str();
    textout_ex(buffer, font_main, life_txt.c_str(), 0, 0, makecol(255, 0, 0), -1);
}

int Level::genericGameLoop()
{
    if(iterations % 4 == 0){
        printMap();
        jack->animation();
        jack->print(buffer);
        printText();
        characters->print(buffer);
        draw_sprite(screen, buffer, 0, 0);
        clear_bitmap(buffer);
        if (key[KEY_C])
        {
            jack->jump();
        }
        if (key[KEY_X])
        {
            jack->JetPack();
        }
        if (key[KEY_Z])
        {
            jack->activeDash();
        }
        if (key[KEY_LEFT])
        {
            jack->move(-1);
        }
        if (key[KEY_RIGHT])
        {
            jack->move(1);
        }
        jack->loop();
        structures->isCollide(static_cast<Mover*>(jack));
        structures->isCollide(characters);
        characters->loop();
    }

    if(iterations % 3 == 0){
        if(characters->isCollide(jack)){
            return 0;
        }
    }

    if(iterations == 5){
        obstacles->isCollide(characters);
    }

    if(iterations % 7 == 0){
        if(obstacles->isCollide(static_cast<Character*>(jack))){
            return 0;
        }
    }

    if(iterations % 13 == 0){
        iterations = 0;
    }

    iterations++;
    return 1;
}

void Level::saveLevel(std::ofstream& myfile) const{
    characters->saveLevel(myfile);
}

void Level::loadLevel(ifstream& myfile){
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
        }
        was_genereted = 1;
    }
    else{
        cout << "Erro ao carregar arquivo!" << endl;
    }
}

Level::~Level()
{}


