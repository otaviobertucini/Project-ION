#include "Level.h"

Level::Level()
{
    //ctor
}

Level::Level(BITMAP* screen):screen(screen){
    map = NULL;
}

void Level::setMap(Map* map){
    this->map = map;
}

Map* Level::getMap(){
    return map;
}

/*This function returns 0 case success and 1 case fails*/
int Level::printMap(){
    if(map == NULL){ //tests if map exists
        cout << "Mapa não existe" << endl;
        return 1;
    }

    BITMAP *stone_1 = load_bitmap("/home/otavio/Documentos/Project_ION/Material/Scenario/stone_1.bmp", NULL);
    int* matrix = map->getMatrix();
    int j = 0;
    int h = 0;
    for(int i = 0; i < 36*24; i++){
        if(j == 36){
            j = 0;
            h++;
        }
        cout << matrix[i] << endl;
        if(matrix[i] == 0)
            blit(stone_1, screen, 0, 0, 30*j, 30*h, 30, 30);
        j++;
    }
}

Level::~Level()
{
    //dtor
}
