#include "Map.h"

Map::Map()
{
    //ctor
}

Map::Map(int** matrix):matrix(matrix){}

int** Map::getMatrix(){
    return matrix;
}

/*Returns the value of the matrix in the given (i, j) position
If at least one of the values is invalid, NULL is returned.*/
int Map::getValueMap(int i, int j){
    if(i > 36 || i < 0 || j > 24 || j < 0)
        return NULL;
    return matrix[i][j];
}

Map::~Map()
{
}
