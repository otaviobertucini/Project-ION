#include "List_Images.h"

List_Images::List_Images()
{}

void List_Images::include(BITMAP* newi){
    images.push_back(newi);
}

int List_Images::empty(){
    return images.empty();
}

BITMAP* List_Images::operator[](int index){
    return images[index];
}

void List_Images::deleteAll(){
    images.erase(images.begin(), images.end());
}

List_Images::~List_Images()
{
    deleteAll();
}
