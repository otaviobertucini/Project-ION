#ifndef LIST_IMAGES_H
#define LIST_IMAGES_H
#include<allegro.h>
//#include <winalleg.h>
#include <cstddef> //library for NULL
#include <vector>
#include "List.h"

class List_Images
{
public:
    List_Images();
    void include(BITMAP* newi);
    void deleteAll();
    int empty();
    int size();
    BITMAP* operator[](int index);
    virtual ~List_Images();
private:
    std::vector<BITMAP*> images;
};

#endif // LIST_IMAGES_H
