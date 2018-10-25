#ifndef ENTITY_H
#define ENTITY_H
#include <allegro.h>
#include <winalleg.h>
#include <cstddef> //library for NULL
#include <iostream>
#include <vector>
#include "List_Images.h"
using std::cout;
using std::endl;

class Entity
{
public:
    Entity();
    Entity(float x, float y, BITMAP* curren_img = NULL);
    virtual void setPosMatrix() = 0;
    void getPosMatrix(int* i, int* j);
    virtual void print(BITMAP* screen) = 0;
    BITMAP* getCurrentImg();
    float GetX();
    float GetY();
    virtual ~Entity();
protected:
    float x;
    float y;
    BITMAP* current_img;
    int i_pos;
    int j_pos;
};

#endif // ENTITY_H
