#ifndef MAP_H
#define MAP_H
#include <cstddef> //library for NULL
#include <iostream>
#include "List_Structures.h"
#include "List_Images.h"
#include "Structure.h"
#include "Stone.h"

using std::cout;
using std::endl;

class Map
{
public:
    Map();
    Map(int** matrix, List_Images *img);
    ~Map();
    int** getMatrix();
    List_Structures* getList();
    int getValueMap(int i, int j);
    void generateStructures();
    void printMap(BITMAP* screen);
private:
    int** matrix;
    List_Structures structures;
    List_Images *img;
};

#endif // MAP_H
