#include "Level.h"

Level::Level()
{
    //ctor
}

Level::Level(BITMAP* buffer, Images *images, Human* jack){
    this->buffer = buffer;
    this->images = images;
    characters = new List_Characters;
    obstacles = new List_Obstacles;
    structures = new List_Structures;
    lavas = new List_Lavas;
    this->jack = jack;
    game_status = 1;
    was_genereted = 0;
    iterations = 0;
    font_main = load_font("Fonts/ImpactFont.pcx", NULL, NULL);
}

int Level::isCollide(Entity* a, Entity* b){
    int x_sum = (a->getw()/2)+(b->getw()/2);
    int y_sum = (a->geth()/2)+(b->geth()/2);
    if((abs((a->getx()+(a->getw()/2)) - (b->getx()+(b->getw()/2))) <= x_sum) &&
       (abs((a->gety()+(a->geth()/2)) - (b->gety()+(b->geth()/2))) <= y_sum )){
        return 1;
    }
    return 0;
}

void Level::generateLevel(List_Characters* characters, List_Powerups* powers, List_Fireballs* fires){
    this->characters = characters;
    //this->powers = powers;
    //this->fireballs = fires;
    was_genereted = 1;
}

//void Level::isStructureCollide(Moveable* a)
//{
//    int i;
//    float x_center,y_center,x_center_body,y_center_body;
//
//    x_center = a->getx()+(a->getw()/2);
//    y_center = a->gety()+(a->geth()/2);
//
//    List_Structures* aux;
//    aux = map->getList();
//
//    a->setLeft(true);
//    a->setRight(true);
//    a->setUp(true);
//    a->setDown(true);
//
//    for(i=0; i<aux->size(); i++)
//    {
//        x_center_body = (*aux)[i]->getx() + 15;
//        y_center_body = (*aux)[i]->gety() + 15;
//
//        //emcima do 2
//        if(a->gety() + a->geth() >= (*aux)[i]->gety() && y_center <= y_center_body
//           && abs(x_center - x_center_body) < (a->getw()/2)+((*aux)[i]->getw()/2)-2)
//        {
//            a->setDown(false);
//            a->sety((*aux)[i]->gety() - a->geth());
//        }
//        //embaixo do 2
//        if(a->gety() <= (*aux)[i]->gety() + (*aux)[i]->geth() && y_center >= y_center_body
//           && abs(x_center - x_center_body) < (a->getw()/2)+((*aux)[i]->getw()/2)-2)
//        {
//            a->setUp(false);
//        }
//        //esquerda do 2
//        if(a->getx() + a->getw() >= (*aux)[i]->getx() && x_center <= x_center_body
//                && abs(y_center - y_center_body) < (a->geth()/2)+((*aux)[i]->geth()/2)-2){
//            a->setRight(false);
//        }
//        //direita do 2
//        if(a->getx() <= (*aux)[i]->getx() + (*aux)[i]->getw() && x_center >= x_center_body
//                && abs(y_center - y_center_body) < (a->geth()/2)+((*aux)[i]->geth()/2)-2){
//            a->setLeft(false);
//        }
//    }
//}

void Level::generateMap(int** matrix){
    bool upStone;
    bool downStone;
    bool leftStone;
    bool rightStone;
    List_Images* img = images->getImgsMap();
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
                            structures->include(static_cast<Structure*>(new Stone(30*j, 30*i, (*img)[13])));
                        else if(leftStone)
                            structures->include(static_cast<Structure*>(new Stone(30*j, 30*i, (*img)[15])));
                        else
                            structures->include(static_cast<Structure*>(new Stone(30*j, 30*i, (*img)[11])));
                    }
                    else if(rightStone)
                    {
                        if(leftStone)
                            structures->include(static_cast<Structure*>(new Stone(30*j, 30*i, (*img)[16])));
                        else
                            structures->include(static_cast<Structure*>(new Stone(30*j, 30*i, (*img)[7])));
                    }
                    else if(leftStone)
                        structures->include(static_cast<Structure*>(new Stone(30*j, 30*i, (*img)[10])));
                    else
                        structures->include(static_cast<Structure*>(new Stone(30*j, 30*i, (*img)[3])));
                }
                else if(rightStone)
                {
                    if(leftStone)
                    {
                        if(downStone)
                            structures->include(static_cast<Structure*>(new Stone(30*j, 30*i, (*img)[14])));
                        else
                            structures->include(static_cast<Structure*>(new Stone(30*j, 30*i, (*img)[12])));
                    }
                    else if(downStone)
                        structures->include(static_cast<Structure*>(new Stone(30*j, 30*i, (*img)[8])));
                    else
                        structures->include(static_cast<Structure*>(new Stone(30*j, 30*i, (*img)[4])));
                }
                else if(downStone)
                {
                    if(leftStone)
                        structures->include(static_cast<Structure*>(new Stone(30*j, 30*i, (*img)[9])));
                    else
                        structures->include(static_cast<Structure*>(new Stone(30*j, 30*i, (*img)[5])));
                }
                else if(leftStone)
                        structures->include(static_cast<Structure*>(new Stone(30*j, 30*i, (*img)[6])));
                else
                {
                    int aux;
                    aux = rand()%3;
                    structures->include(static_cast<Structure*>(new Stone(30*j, 30*i, (*img)[aux])));
                }
            }
            else if(matrix[i][j] == 2){
                Lava* aux;
                if(matrix[i-1][j] != 2 && matrix[i-1][j] != 3)
                    aux = new Lava(30*j, 30*i, (*img)[18]);
                else
                    aux = new Lava(30*j, 30*i, (*img)[17]);

                obstacles->include(static_cast<Obstacle*>(aux));
            }
            else if(matrix[i][j] == 3){
                Lava* aux = new Lava(30*j, 30*i, (*img)[18]);
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
                    obstacles->include(static_cast<Obstacle*>(new Spine(30*j, 30*i, (*img)[side])));
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

float Level::getXInitial()
{
    return x_initial;
}

float Level::getYInitial()
{
    return y_initial;
}

void Level::resetPlayer(){
    jack->setx(x_initial);
    jack->sety(y_initial);
    jack->setUp(false);
    jack->setDown(false);
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
    //powers->eraseAll();
    was_genereted = 0;
}

int Level::genericGameLoop()
{
    if(iterations % 4 == 0){
        printMap();
        jack->print(buffer);
        characters->print(buffer);
        textout_ex(buffer, font_main, "iaiaiai", 0, 0, makecol(0, 0, 255), -1);
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
        structures->isCollide(static_cast<Moveable*>(jack));
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

List_Characters* Level::getListCharacters(){
    return characters;
}

Level::~Level()
{
    characters->deleteAll();
}


