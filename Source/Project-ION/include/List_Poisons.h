#ifndef LIST_POISONS_H
#define LIST_POISONS_H
#include "List.h"
#include "Poison.h"
#include "Human.h"

class List_Poisons
{
public:
    List_Poisons();
    void include(Poison* newl);
    int size();
    void eraseAll();
    void loop();
    void print(BITMAP* buffer);
    int isCollide(Human* a);
    void del(int i);
    Poison* operator[](int index);
    virtual ~List_Poisons();
private:
    std::vector<Poison*> poisons;
};

#endif // LIST_POISONS_H
