#ifndef LIST_HANDLES_H
#define LIST_HANDLES_H
#include "List.h"
#include "Handle.h"
#include "Human.h"

class List_Handles
{
public:
    List_Handles();
    void include(Handle* newl);
    int size();
    void print(BITMAP* buffer);
    void eraseAll();
    Handle* isCollide(Human* a);
    virtual ~List_Handles();
private:
    List<Handle*> handles;
};

#endif // LIST_HANDLES_H
