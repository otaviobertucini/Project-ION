#ifndef ENTITY_H
#define ENTITY_H
#include <allegro.h>
//#include <winalleg.h>
#include <cstddef> //library for NULL
#include <iostream>
#include <vector>
#include "List_Images.h"
#include "Images.h"
using std::cout;
using std::endl;

class Entity
{
public:
    Entity();
    Entity(float x, float y);
    virtual void print(BITMAP* screen);
    BITMAP* getCurrentImg();
    void setCurrentImg(BITMAP* img);
    const float getx() const;
    const float gety() const;
    const int getw() const;
    const int geth() const;
    void sety(const float new_y);
    void setx(const float new_x);
    virtual ~Entity();
protected:
    float x;
    float y;
    BITMAP* current_img;
    int w; //Width
    int h; //Height
};

#endif // ENTITY_H
