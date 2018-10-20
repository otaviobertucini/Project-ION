#include "Level.h"

Level::Level()
{
    //ctor
}

Level::Level(BITMAP* buffer, List_Images *img):buffer(buffer){
    map = NULL;
    this->img = img;
}

void Level::setMap(Map* map){
    this->map = map;
}

Map* Level::getMap(){
    return map;
}

/*This function print the background of the level. Returns 0 case success and 1 case fails*/
int Level::printMap(){
    if(map == NULL){ //tests if map exists
        cout << "Mapa não existe" << endl;
        return 1;
    }

    int** matrix = map->getMatrix();
    for(int i = 0; i<24; i++){
        for(int j = 0; j<36; j++){
            if(matrix[i][j] == 0)
                blit((*img)[0], buffer, 0, 0, 30*j, 30*i, 30, 30);
        }
    }
    return 0;
}

//Update all the positions of the characters placed in the level.
void Level::updatePosition(){
    vector<Character*>::iterator itr = characters.begin();
    for(; itr != characters.end(); itr++){
        (*itr)->print(buffer);
    }
}

int Level::getValueMap(int i, int j){
    return map->getValueMap(i, j);
}

Level::~Level()
{
    std::vector<Character*>::iterator itr = characters.begin();
    for(; itr != characters.end(); itr++)
        delete *itr;
    characters.clear();
}
