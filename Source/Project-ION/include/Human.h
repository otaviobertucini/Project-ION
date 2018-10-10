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
        Human(string name, int x, int y, int x_speed, int y_speed, std::vector<BITMAP*> *img);
        ~Human();
        void move(int x_move, int y_move);
        void printCharacter(BITMAP* screen);
    private:
        string name;
};

#endif // HUMAN_H
