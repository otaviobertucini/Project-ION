#include "Map.h"

Map::Map()
{
    //ctor
}

Map::Map(int* matrix):matrix(matrix){}

int* Map::getMatrix(){
    return matrix;
}

//This function returns the value of the map matrix in the i-j position.
int Map::getValueMap(int i, int j){
    if(i > 36 || i < 0 || j > 24 || j < 0)
        return NULL;
    return matrix[i*36+j];
}

Map::~Map()
{
    //dtor
}
