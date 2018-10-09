#include "Map.h"

Map::Map()
{
    //ctor
}

Map::Map(int* matrix):matrix(matrix){}

int* Map::getMatrix(){
    return matrix;
}

Map::~Map()
{
    //dtor
}
