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
        //esquerda do 29
        if(a->getx() + a->getw() >= (*aux)[i]->getx() && x_center <= x_center_body
                && abs(y_center - y_center_body) < (a->geth()/2)+((*aux)[i]->geth()/2)-2){
            a->setRight(false);
        }
        //direita do 2
        if(a->getx() <= (*aux)[i]->getx() + (*aux)[i]->getw() && (*aux)[i]->getx() && x_center >= x_center_body
                && abs(y_center - y_center_body) < (a->geth()/2)+((*aux)[i]->geth()/2)-2){
            a->setLeft(false);
        }
    }
}

//int Level::isBlockCollide(Character* a, Entity* block){
//    float x_center = a->getx()+(a->getw()/2);
//    float y_center = a->gety()+(a->geth()/2);
//    float x_center_body = block->getx() + 15;
//    float y_center_body = block->gety() + 15;
//
//    if(a->gety() + a->geth() >= block->gety() && y_center <= y_center_body)
//    {
//        return 1;
//    }
//    //embaixo do 2
//    if(a->gety() <= block->gety() + block->geth() && y_center >= y_center_body)
//    {
//        return 1;
//    }
//    //esquerda do 29
//    if(a->getx() + a->getw() >= block->getx() && x_center <= x_center_body)
//    {
//        return 1;
//    }
//    //direita do 2
//    if(a->getx() <= block->getx() + block->getw() && x_center >= x_center_body)
//
//    {
//        return 1;
//    }
//    return 0;
//}

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
}

void Level::loopCharacters(){
    for(int i = 0; i < characters->size(); i++){
        (*characters)[i]->loop();
    }
}

void Level::collisionCharacters(){
    for(int i = 0; i < characters->size(); i++){
        isStructureCollide((*characters)[i]);
    }
}

int Level::isCharacterCollide(Character* a){
    for(int i = 0; i<characters->size(); i++){
        if(isCollide(static_cast<Entity*>(a), static_cast<Entity*>((*characters)[i])))
            return 1;
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
    for(int i = 0; i < fireballs.size(); i++){
        if(isCollide(static_cast<Entity*>(a), static_cast<Entity*>(fireballs[i]))){
            return 1;
        }
    }
    return 0;
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
    was_genereted = 0;
}

int Level::genericGameLoop()
{
    printMap();
    if (key[KEY_C])
    {
        jack->jump();
    }
    if (key[KEY_X] && !(key[KEY_DOWN]))
    {
        jack->JetPack();
    }
    if (key[KEY_X] && key[KEY_DOWN])
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

    if(isCharacterCollide(static_cast<Character*>(jack)))
        return 0;

    if(isObstacleCollide(static_cast<Character*>(jack)))
        return 0;

    if(isFireballCollide(static_cast<Character*>(jack)))
        return 0;

    updatePosition();

    return 1;
}

void Level::loopFireballs(){
    Fireball* fire = (*lavas)[0]->createFireball();
    if(fire != NULL){
        fireballs.push_back(fire);
    }

    for(int i = 0; i<fireballs.size(); i++){
        fireballs[i]->loop();
        isStructureCollide(static_cast<Character*>(fireballs[i]));
        if(!fireballs[i]->getMoveUp()){
            fireballs.erase(fireballs.begin() + i);
        }
        fireballs[i]->print(buffer);
    }
}

List_Characters* Level::getListCharacters(){
    return characters;
}

Level::~Level()
{
    characters->deleteAll();
    delete jack;
    jack = NULL;
}


