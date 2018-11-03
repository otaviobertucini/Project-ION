#ifndef HUMAN_H
#define HUMAN_H
#include <string>
#include <iterator>
#include <iostream>
#include <math.h>
#include "Character.h"
using namespace std;
using std::cout;
using std::endl;

class Human:public Character
{
    public:
        Human();
        Human(string name, float x, float y, List_Images *img, int direction = 1);
        ~Human();
        void move(int x_move);
        void print(BITMAP* screen);
        void setPosMatrix();
        void gravity();
        void jump();
        void JetPack();
        void activeDash();
        void dash();
        void loop();
    private:
        string name;
        float y_force;
        bool charge;
        bool dashOn;
        float distance_dash;
};

#endif // HUMAN_H
