#include "Map.h"

Map::Map()
{
    //ctor
}

Map::Map(int** matrix, List_Images *img){
    this->matrix = matrix;
    this->img = img;
    generateStructures();
}

void Map::generateStructures(){
    for(int i = 0; i<24; i++){
        for(int j = 0; j<36; j++){
            if(matrix[i][j] == 0)
                structures.include(static_cast<Structure*>(new Stone(30*j, 30*i, (*img)[0])));
            else if(matrix[i][j] == 2){
                Lava* aux = new Lava(30*j, 30*i, (*img)[1]);
                obstacles.include(static_cast<Obstacle*>(aux));
            }
            else if(matrix[i][j] == 3){
                Lava* aux = new Lava(30*j, 30*i, (*img)[2]);
                obstacles.include(static_cast<Obstacle*>(aux));
                lavas.include(aux);
            }
            else if(matrix[i][j] == 4){
                int side;
                if(matrix[i-1][j] == 0){
                    side = 5;
                }
                else if(matrix[i+1][j] == 0){
                    side = 3;
                }
                else if(matrix[i][j+1] == 0){
                    side = 6;
                }
                else if(matrix[i][j-1] == 0){
                    side = 4;
                }
                obstacles.include(static_cast<Obstacle*>(new Spine(30*j, 30*i, (*img)[side])));
            }
            else if(matrix[i][j] == 20){
                powers.include(static_cast<Powerup*>(new Birl(30*j, 30*i, (*img)[7])));
            }
        }
    }
}

void Map::printMap(BITMAP* screen){
    for(int i = 0; i<structures.size(); i++){
        structures[i]->print(screen);
    }
    for(int i = 0; i<obstacles.size(); i++){
        obstacles[i]->print(screen);
    }
}

int** Map::getMatrix(){
    return matrix;
}

/*Returns the value of the matrix in the given (i, j) position
If at least one of the values is invalid, NULL is returned.*/
int Map::getValueMap(int i, int j){
    if(j > 35 || j < 0 || i > 23 || i < 0)
        return -1;
    return matrix[i][j];
}

List_Structures* Map::getList()
{
    return &structures;
}

List_Obstacles* Map::getListObstacles(){
    return &obstacles;
}

List_Lavas* Map::getListLavas(){
    return &lavas;
}

List_Powerups* Map::getListPowers(){
    return &powers;
}

Map::~Map()
{
    for(int i = 0; i<24; i++)
        delete[] matrix[i];
    delete[] matrix;
    matrix = NULL;
}
