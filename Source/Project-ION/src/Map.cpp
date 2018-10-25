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
        }
    }
}

void Map::printMap(BITMAP* screen){
    for(int i = 0; i<structures.size(); i++){
        structures[i]->print(screen);
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

Map::~Map()
{
    for(int i = 0; i<24; i++)
        delete[] matrix[i];
    delete[] matrix;
    matrix = NULL;
}

List_Structures* Map::getList()
{
    return &structures;
}
