#ifndef CHARACTER_H
#define CHARACTER_H
#include <allegro.h>
//#include <winalleg.h>
#include <cstddef> //library for NULL
#include <math.h>
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include "Entity.h"
#include "Moveable.h"
#include "List_Images.h"

using std::cout;
using std::endl;

class Character: public Moveable
{
public:
    Character();
    Character(float x, float y, List_Images *img);
    ~Character();
    virtual void loop() = 0;
    virtual void gravity();
    void operator++(int n);
protected:
    std::string type;
    int current_side;
    float x_speed;  // Values that will be
    float y_speed;  // increased/decreased when moving.
    List_Images *img;
    float y_force;
};

#endif // CHARACTER_H
