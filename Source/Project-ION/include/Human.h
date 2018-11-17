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
        Human(string name, float x, float y, List_Images *img, int direction = 1, bool powerup_on = 0);
        ~Human();
        void move(int x_move);
        void gravity();
        void jump();
        void JetPack();
        void activeDash();
        void dash();
        void loop();
        void turnPowerup(const bool state = true);
        const bool isPowered() const;
        int getLifes();
        void lessLife();
        void resetLifes();
        void saveState(std::ofstream& myfile) const;
        void setLifes(const int lifes);
    private:
        string name;
        float y_force;
        bool charge;
        bool dashOn;
        float distance_dash;
        bool powerup_on;
        const float x_force;
        int lifes;
};

#endif // HUMAN_H
