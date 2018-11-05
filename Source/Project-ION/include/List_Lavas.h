#ifndef LIST_LAVAS_H
#define LIST_LAVAS_H
#include <vector>
#include "Lava.h"

class List_Lavas
{
public:
    List_Lavas();
    void include(Lava* newl);
    void deleteAll();
    int empty();
    int size();
    void eraseAll();
    Lava* operator[](int index);
    virtual ~List_Lavas();
private:
    std::vector<Lava*> lavas;

};

#endif // LIST_LAVAS_H
