#ifndef CHARACTER_H
#define CHARACTER_H
#include <allegro.h>
#include <cstddef> //library for NULL
#include <vector>

class Character
{
public:
    Character();
    Character(int x, int y, int x_speed, int y_speed, std::vector<BITMAP*> *img);
    ~Character();
    virtual void move(int x_move, int y_move) = 0;
    virtual void printCharacter(BITMAP* screen) = 0;
protected:
    int x;
    int y;
    int x_speed;
    int y_speed;
    std::vector<BITMAP*> *img; //This vector stores the images that the character will use.
};

#endif // CHARACTER_H
