#ifndef ENTITY_H
#define ENTITY_H
#include <allegro.h>
#include <vector>
#include "List_Images.h"

class Entity
{
public:
    Entity();
    Entity(float x, float y, List_Images *img);
    virtual void setPosMatrix() = 0;
    void getPosMatrix(int* i, int* j);
    virtual void print(BITMAP* screen) = 0;
    virtual ~Entity();
protected:
    float x;
    float y;
    List_Images *img;
    int i_pos;
    int j_pos;
};

#endif // ENTITY_H
