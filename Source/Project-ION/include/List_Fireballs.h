#ifndef LIST_FIREBALLS_H
#define LIST_FIREBALLS_H
#include <vector>
#include "Fireball.h"

class List_Fireballs
{
public:
    List_Fireballs();
    void include(Fireball* newc);
    void deleteAll();
    int empty();
    int size();
    void erase(int i);
    void eraseAll();
    Fireball* operator[](int index);
    virtual ~List_Fireballs();
private:
    std::vector<Fireball*> fireballs;

};

#endif // LIST_FIREBALLS_H
