#include "Level.h"

Level::Level()
{
    //ctor
}

Level::Level(BITMAP* buffer, List_Images *img):buffer(buffer){
    map = NULL;
}

void Level::setMap(Map* map){
    this->map = map;
}

Map* Level::getMap(){
    return map;
}

/*This function print the background of the level. Returns 0 case success and 1 case fails*/
int Level::printMap(){
    map->printMap(buffer);
    return 1;
}

////Update all the positions of the characters placed in the level.
//void Level::updatePosition(){
//    vector<Character*>::iterator itr = characters.begin();
//    for(; itr != characters.end(); itr++){
//        (*itr)->print(buffer);
//    }
//}

int Level::getValueMap(int i, int j){
    return map->getValueMap(i, j);
}

Level::~Level()
{
//    std::vector<Character*>::iterator itr = characters.begin();
//    for(; itr != characters.end(); itr++)
//        delete *itr;
//    characters.clear();
}
