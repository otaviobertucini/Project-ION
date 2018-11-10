#include "Level.h"

Level::Level()
{
    //ctor
}

Level::Level(BITMAP* buffer, Images *images, Human* jack){
    map = NULL;
    this->buffer = buffer;
    this->images = images;
    characters = new List_Characters;
    this->jack = jack;
    game_status = 1;
    was_genereted = 0;
    iterations = 0;
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

void Level::isStructureCollide(Character* a)
{
    int i;
    float x_center,y_center,x_center_body,y_center_body;

    x_center = a->getx()+(a->getw()/2);
    y_center = a->gety()+(a->geth()/2);

    List_Structures* aux;
    aux = map->getList();

    a->setLeft(true);
    a->setRight(true);
    a->setUp(true);
    a->setDown(true);

    for(i=0; i<aux->size(); i++)
    {
        x_center_body = (*aux)[i]->getx() + 15;
        y_center_body = (*aux)[i]->gety() + 15;

        //emcima do 2
        if(a->gety() + a->geth() >= (*aux)[i]->gety() && y_center <= y_center_body
           && abs(x_center - x_center_body) < (a->getw()/2)+((*aux)[i]->getw()/2)-2)
        {
            a->setDown(false);
            a->sety((*aux)[i]->gety() - a->geth());
        }
        //embaixo do 2
        if(a->gety() <= (*aux)[i]->gety() + (*aux)[i]->geth() && y_center >= y_center_body
           && abs(x_center - x_center_body) < (a->getw()/2)+((*aux)[i]->getw()/2)-2)
        {
            a->setUp(false);
        }
        //esquerda do 2
        if(a->getx() + a->getw() >= (*aux)[i]->getx() && x_center <= x_center_body
                && abs(y_center - y_center_body) < (a->geth()/2)+((*aux)[i]->geth()/2)-2){
            a->setRight(false);
        }
        //direita do 2
        if(a->getx() <= (*aux)[i]->getx() + (*aux)[i]->getw() && x_center >= x_center_body
                && abs(y_center - y_center_body) < (a->geth()/2)+((*aux)[i]->geth()/2)-2){
            a->setLeft(false);
        }
    }
}

Map* Level::getMap(){
    return map;
}

/*This function print the background of the level.*/
void Level::printMap(){
    map->printMap(buffer);
}

//Update all the positions of the characters placed in the level.
void Level::updatePosition(){
    for(int i = 0; i < characters->size(); i++){
        (*characters)[i]->print(buffer);
    }
    for(int i = 0; i < fireballs.size(); i++){
        fireballs[i]->print(buffer);
    }
}

void Level::loopCharacters(){

    for(int i = 0; i < characters->size(); i++){
        (*characters)[i]->loop();
        if(isObstacleCollide((*characters)[i])){
            delete (*characters)[i];
            //(*characters)[i] = NULL;
            characters->erase(i);
        }
    }
}

void Level::collisionCharacters(){
    for(int i = 0; i < characters->size(); i++){
        isStructureCollide((*characters)[i]);
    }
}

int Level::isCharacterCollide(Human* a){
    for(int i = 0; i<characters->size(); i++){
        if(isCollide(static_cast<Entity*>(a), static_cast<Entity*>((*characters)[i]))){
            if(a->isInvincible()){
                //a->toInvincible(false);
                return 0;
            }
            return 1;
        }

    }
    return 0;
}

int Level::isObstacleCollide(Character* a){
    List_Obstacles* aux = map->getListObstacles();
    for(int i = 0; i<aux->size(); i++){
        if(isCollide(static_cast<Entity*>(a), static_cast<Entity*>((*aux)[i]))){
            return 1;
        }
    }
    return 0;
}

int Level::isFireballCollide(Character* a){
    for(unsigned int i = 0; i < fireballs.size(); i++){
        if(isCollide(static_cast<Entity*>(a), static_cast<Entity*>(fireballs[i]))){
            return 1;
        }
    }
    return 0;
}

int Level::isPowerupCollide(Human* a){
    for(unsigned int i = 0; i < powers->size(); i++){
        if(isCollide(static_cast<Entity*>(a), static_cast<Entity*>((*powers)[i]))){
            //(*powers)[i]->modify(a);
            delete (*powers)[i];
            //(*powers)[i] = NULL;
            powers->erase(i);
        return 1;
        }
    }
    return 0;
}

void Level::loopPowerups(){
    for(int i = 0; i < powers->size(); i++){
        (*powers)[i]->print(buffer);
    }
}

int Level::getValueMap(int i, int j){
    return map->getValueMap(i, j);
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
    fireballs.erase(fireballs.begin(), fireballs.end());
    was_genereted = 0;
}

int Level::genericGameLoop()
{
    if(iterations % 4 == 0){
        printMap();
        jack->print(buffer);
        updatePosition();
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
        isStructureCollide(static_cast<Character*>(jack));
        loopCharacters();
    }

    if(iterations % 3 == 0){

        if(isCharacterCollide(jack)){
            return 0;
        }
        collisionCharacters();
    }

    if(iterations % 7 == 0){

        if(isObstacleCollide(static_cast<Character*>(jack))){
            return 0;
        }
    }

    if(iterations % 13 == 0){
        createFireball();
        loopFireballs();

        if(isFireballCollide(static_cast<Character*>(jack))){
            return 0;
        }
        iterations = 0;
    }

    iterations++;
    return 1;
}

void Level::loopFireballs()
{
    for(int i = 0; i<fireballs.size(); i++){
        fireballs[i]->loop();
        isStructureCollide(static_cast<Character*>(fireballs[i]));
        if(!fireballs[i]->getMoveUp()){
            delete fireballs[i];
            fireballs[i] = NULL;
            fireballs.erase(fireballs.begin() + i);
        }
    }
}

void Level::createFireball(){
    for(int i = 0; i < lavas->size(); i++){
        Fireball* fire = (*lavas)[i]->createFireball();
        if(fire != NULL){
            fireballs.push_back(fire);
        }
    }
}

List_Characters* Level::getListCharacters(){
    return characters;
}

Level::~Level()
{
    characters->deleteAll();
}


