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
        void setPosMatrix();
        void gravity();
        void jump();
        void JetPack();
        void activeDash();
        void dash();
        void loop();
        void toInvincible(bool state = true);
        bool isInvincible();
        void turnPowerup(bool state = true);
        bool isPowered();
    private:
        string name;
        float y_force;
        bool charge;
        bool dashOn;
        float distance_dash;
        bool invincible;
        bool powerup_on;
};

#endif // HUMAN_H
