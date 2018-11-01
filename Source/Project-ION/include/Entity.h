#ifndef ENTITY_H
#define ENTITY_H
#include <allegro.h>
//#include <winalleg.h>
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
    float getx();
    float gety();
    int getw();
    int geth();
    void sety(float new_y);
    void setx(float new_x);
    virtual void loop() = 0;
    virtual ~Entity();
protected:
    float x;
    float y;
    BITMAP* current_img;
    int i_pos;
    int j_pos;
    int w; //Width
    int h; //Height
};

#endif // ENTITY_H
