#ifndef LIST_STRUCTURES_H
#define LIST_STRUCTURES_H
#include "Structure.h"

class List_Structures
{
public:
    List_Structures();
    void include(Structure* news);
    void deleteAll();
    int empty();
    int size();
    Structure* operator[](int index);
    virtual ~List_Structures();
private:
    List<Structure*> structures;
};

#endif // LIST_STRUCTURES_H
