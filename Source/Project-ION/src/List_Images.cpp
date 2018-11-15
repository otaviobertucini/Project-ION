#include "List_Images.h"

List_Images::List_Images()
{}

void List_Images::include(BITMAP* newi){
    images.push_back(newi);
}

int List_Images::empty(){
    return images.empty();
}

int List_Images::size(){
    return images.size();
}

BITMAP* List_Images::operator[](int index){
    return images[index];
}

void List_Images::deleteAll(){
    for(int i = 0; i < size(); i++){
        destroy_bitmap(images[i]);
        images[i] = NULL;
    }
    images.clear();
}

List_Images::~List_Images()
{
    deleteAll();
}
