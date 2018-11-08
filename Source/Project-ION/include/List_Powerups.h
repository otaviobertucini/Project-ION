#ifndef LIST_POWERUPS_H
#define LIST_POWERUPS_H
#include "Powerup.h"
#include <vector>

class List_Powerups
{
public:
    List_Powerups();
    void include(Powerup* newp);
    void deleteAll();
    int empty();
    int size();
    void erase(int i);
    void eraseAll();
    Powerup* operator[](int index);
    virtual ~List_Powerups();
private:
    std::vector<Powerup*> powers;
};

#endif // LIST_POWERUPS_H
