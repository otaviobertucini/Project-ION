#ifndef LIST_STRUCTURES_H
#define LIST_STRUCTURES_H
#include "Structure.h"
#include "Moveable.h"
#include "List_Characters.h"
#include "List_Fireballs.h"
#include "List_Poisons.h"

class List_Structures
{
public:
    List_Structures();
    void include(Structure* news);
    void deleteAll();
    int empty();
    int size();
    void print(BITMAP* buffer);
    int isCollide(Moveable* a);
    int isCollide(List_Characters* chars);
    int isCollide(List_Fireballs* fires);
    int isCollide(List_Poisons* poisons);
    Structure* operator[](int index);
    virtual ~List_Structures();
private:
    std::vector<Structure*> structures;
};

#endif // LIST_STRUCTURES_H
