#ifndef MAP_H
#define MAP_H
#include <cstddef> //library for NULL
#include <iostream>
using std::cout;
using std::endl;

class Map
{
public:
    Map();
    Map(int** matrix);
    ~Map();
    int** getMatrix();
    int getValueMap(int i, int j);
private:
    int** matrix;
};

#endif // MAP_H
