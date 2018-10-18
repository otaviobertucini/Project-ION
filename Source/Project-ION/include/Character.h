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
    float x; //Position in x-axis.
    float y; //Position in the y-axis.
    float x_speed;  // Values that will be
    float y_speed;  // increased/decreased when moving.
    std::vector<BITMAP*> *img; //This vector stores the images that the character will use.
    int i_pos; //Current position of character in the matrix (x-axis).
    int j_pos; //Current position of character in the matrix (y-axis).
};

#endif // CHARACTER_H
