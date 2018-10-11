#ifndef CHARACTER_H
#define CHARACTER_H
#include <allegro.h>
#include <cstddef> //library for NULL
#include <math.h>
#include <vector>
#include <iostream>
using std::cout;
using std::endl;

class Character
{
public:
    Character();
    Character(float x, float y, float x_speed, float y_speed, std::vector<BITMAP*> *img);
    ~Character();
    virtual void move(int x_move, int y_move) = 0;
    virtual void printCharacter(BITMAP* screen) = 0;
    virtual void getPosMatrix(int *i, int *j);
protected:
    float x;
    float y;
    float x_speed;
    float y_speed;
    std::vector<BITMAP*> *img; //This vector stores the images that the character will use.
};

#endif // CHARACTER_H
