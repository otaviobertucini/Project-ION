#ifndef LIST_POWERUPS_H
#define LIST_POWERUPS_H
#include "Powerup.h"
#include <vector>

class List_Powerups
{
public:
    List_Powerups();
    void include(Powerup* newp);
    int size();
    void erase(int i);
    void eraseAll();
    int isCollide(Human* a);
    void print(BITMAP* buffer);
    void saveLevel(std::ofstream& myfile);
    Powerup* operator[](int index);
    virtual ~List_Powerups();
private:
    std::vector<Powerup*> powers;
};

#endif // LIST_POWERUPS_H
