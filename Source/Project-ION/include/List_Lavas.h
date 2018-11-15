#ifndef LIST_LAVAS_H
#define LIST_LAVAS_H
#include <vector>
#include "Lava.h"
#include "List_Fireballs.h"
#include "List.h"

class List_Lavas
{
public:
    List_Lavas();
    void include(Lava* newl);
    int size();
    void eraseAll();
    Lava* operator[](int index);
    void createFireballs(List_Fireballs* fires);
    virtual ~List_Lavas();
private:
    List<Lava*> lavas;
};

#endif // LIST_LAVAS_H
