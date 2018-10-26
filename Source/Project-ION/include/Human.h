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
        void move(int x_move);
        void print(BITMAP* screen);
        void setPosMatrix();
        void isStructureCollide();
        int isCollide(Entity* Body);
        void gravity();
        void jump();
    private:
        string name;
        float y_force;

};

#endif // HUMAN_H
