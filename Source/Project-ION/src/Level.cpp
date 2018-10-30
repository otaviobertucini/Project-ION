#include "Level.h"

Level::Level()
{
    //ctor
}

Level::Level(BITMAP* buffer, Images *images){
    map = NULL;
    this->buffer = buffer;
    this->images = images;
    entities = new List_Entities;
}

int Level::isCollide(Entity* a, Entity* b){
    int x_sum = (a->getw()/2)+(b->getw()/2);
    int y_sum = (a->geth()/2)+(b->geth()/2);
    if((abs(a->getx() - b->getx()) < x_sum) && (abs(a->gety() - b->gety()) < y_sum ))
        return 1;
    return 0;
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
    for(int i = 0; i < entities->size(); i++){
        (*entities)[i]->print(buffer);
    }
}

void Level::loopEntities(){
    for(int i = 0; i < entities->size(); i++){
        (*entities)[i]->loop();
    }
}

int Level::getValueMap(int i, int j){
    return map->getValueMap(i, j);
}

Level::~Level()
{
    entities->deleteAll();
    delete jack;
}
