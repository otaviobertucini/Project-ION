#ifndef MAP_H
#define MAP_H

class Map
{
public:
    Map();
    Map(int* matrix);
    ~Map();
    int* getMatrix();
private:
    int* matrix;
};

#endif // MAP_H
