#include "List_Images.h"

List_Images::List_Images()
{}

void List_Images::include(BITMAP* newi){
    images.include(newi);
}

int List_Images::empty(){
    return images.empty();
}

BITMAP* List_Images::operator[](int index){
    return images[index];
}

void List_Images::deleteAll(){
    images.deleteAll();
}

List_Images::~List_Images()
{
    deleteAll();
}
