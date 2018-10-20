#ifndef HUMAN_H
#define HUMAN_H
#include <string>
#include <iterator>
#include <iostream>
#include "Character.h"
using namespace std;
using std::cout;
using std::endl;

class Human:public Character
{
    public:
        Human();
        Human(string name, float x, float y, float x_speed, float y_speed, List_Images *img);
        ~Human();
        void move(int x_move, int y_move);
        void print(BITMAP* screen);
        void setPosMatrix();
    private:
        string name;
};

#endif // HUMAN_H
